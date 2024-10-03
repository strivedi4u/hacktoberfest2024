import requests
from bs4 import BeautifulSoup
import json

# URL of the news website to scrape
url = 'https://www.bbc.com/news'  # Replace with the actual news website

# Send a GET request to the website
response = requests.get(url)

# Check if the request was successful (status code 200)
if response.status_code == 200:
    # Parse the HTML content of the page
    soup = BeautifulSoup(response.text, 'html.parser')

    # Find all the articles on the page
    articles = soup.find_all('article')  # Adjust the tag based on the website structure

    # Initialize a list to store extracted data
    extracted_data = []

    for article in articles:
        # Extract the title and link from each article
        title = article.find('h2').get_text()  # Adjust based on the website structure
        link = article.find('a')['href']  # Adjust based on the website structure

        # Append the extracted data to the list
        extracted_data.append({
            'title': title,
            'link': link
        })

    # Convert the list to JSON format
    json_data = json.dumps(extracted_data, indent=4)

    # Print the JSON data
    print(json_data)

else:
    print(f"Failed to retrieve the webpage. Status code: {response.status_code}")
