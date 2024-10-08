from cassandra.cluster import Cluster
from cassandra.auth import PlainTextAuthProvider
from langchain.memory import CassandraChatMessageHistory, ConversationBufferMemory
from langchain.llms import OpenAI
from langchain.prompts import PromptTemplate
from langchain.chains import LLMChain
import json

# Configuration for connecting to the Cassandra database
cloud_config = {
    'secure_connect_bundle': 'secure-connect-choose-your-own-adventure.zip'
}

# Load secrets from a JSON file
with open("choose_your_own_adventure-token.json") as f:
    secrets = json.load(f)

# Extract credentials and keyspace information
CLIENT_ID = secrets["clientId"]
CLIENT_SECRET = secrets["secret"]
ASTRA_DB_KEYSPACE = "database"
OPENAI_API_KEY = ""  # Placeholder for OpenAI API key

# Set up authentication and connect to the Cassandra cluster
auth_provider = PlainTextAuthProvider(CLIENT_ID, CLIENT_SECRET)
cluster = Cluster(cloud=cloud_config, auth_provider=auth_provider)
session = cluster.connect()

# Initialize message history storage in Cassandra
message_history = CassandraChatMessageHistory(
    session_id="anything",  # Unique session identifier
    session=session,        # Cassandra session
    keyspace=ASTRA_DB_KEYSPACE,  # Keyspace in Cassandra
    ttl_seconds=3600        # Time-to-live for messages in seconds
)

# Clear any existing message history
message_history.clear()

# Set up conversation buffer memory to store chat history
cass_buff_memory = ConversationBufferMemory(
    memory_key="chat_history",  # Key for storing chat history
    chat_memory=message_history  # Reference to Cassandra message history
)
