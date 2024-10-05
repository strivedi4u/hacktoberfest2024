from PIL import Image
import pytesseract
from IPython.display import display
from io import BytesIO
from ipywidgets import FileUpload

# Set the path to the Tesseract executable if necessary
# pytesseract.pytesseract.tesseract_cmd = r'C:\Program Files\Tesseract-OCR\tesseract.exe'  # Update this if needed

# Function to handle file upload and extract text
def upload_and_extract_text():
    uploader = FileUpload(accept='image/*', multiple=False)
    display(uploader)

    def on_upload_change(change):
        if uploader.value:
            # Get the uploaded file (the first file in the dictionary)
            file_info = next(iter(uploader.value.values()))  # Access the first uploaded file
            
            # Use BytesIO to open the image from the content
            img = Image.open(BytesIO(file_info['content']))  # Convert bytes to an image
            
            # Display the uploaded image
            display(img)  # Display the image directly
            
            # Use pytesseract to extract text
            extracted_text = pytesseract.image_to_string(img)
            
            # Debugging output
            print("Extracted Text:")
            print(extracted_text if extracted_text else "No text found.")

    uploader.observe(on_upload_change, names='value')

# Run the function
upload_and_extract_text()
