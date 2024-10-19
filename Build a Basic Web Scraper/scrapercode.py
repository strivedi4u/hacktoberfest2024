import requests
from bs4 import BeautifulSoup
import json
from urllib.parse import urljoin

# URL of the news website to scrape
url = 'https://www.bbc.com/news'

# Send a GET request to the website
response = requests.get(url)

# Check if the request was successful (status code 200)
if response.status_code == 200:
    # Parse the HTML content of the page
    soup = BeautifulSoup(response.text, 'html.parser')

    # Find all articles or news blocks on the page
    articles = soup.find_all('article')

    # Initialize a list to store extracted data
    extracted_data = []

    for article in articles:
        # Safely extract title and link with error handling
        title_tag = article.find('h3') or article.find('h2')  # Try both tags for flexibility
        title = title_tag.get_text(strip=True) if title_tag else 'No title available'
        
        # Handle relative and absolute URLs
        link_tag = article.find('a')
        if link_tag:
            link = urljoin(url, link_tag.get('href', '#'))
        else:
            link = 'No link available'

        # Optionally extract other metadata like publication date
        pub_time_tag = article.find('time')
        pub_time = pub_time_tag.get('datetime') if pub_time_tag else 'No date available'

        # Append the extracted data to the list
        extracted_data.append({
            'title': title,
            'link': link,
            'publication_time': pub_time
        })

    # Convert the list to JSON format
    json_data = json.dumps(extracted_data, indent=4)

    # Print the JSON data
    print(json_data)

else:
    print(f"Failed to retrieve the webpage. Status code: {response.status_code}")
