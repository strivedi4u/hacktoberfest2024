# Getting Started 




## Available Scripts

In the project directory, you can run:

* to install the dependencies:

### 'npm install'

* to run the project

### `npm start`

### Functionalities
* Input seller details, billing details, shipping details, order details, invoice details, item details.

* Add multiple items with details like decription, quantity, unit price, and discount.
* Calculate the net amount automatically for each item.
* Check if it falls under the category of IGST or CGST,SGST.
* Calculate the IGST or CGST, SGST amount.
* Calculate the total according to the netAmount. (Due to lack of time I'm unable to calculate the total according to the IGST or CSGT,SGST. If given some more time. I can complete that task as well)

* Validate the items, there is description, unit price for each and every item or else error will me shown.
* The net amount cannot be edited as it is calculated via calculateNetAmount() function.
* The net amount is shown in words.
* Preview the uploaded signature.
* Generate a formatted invoice in PDF format with a total amount and a signature .

### Directories
* components/: Contains all the main React components used in the app.
* utils/: Contains utility functions for calculations and form validation.

### Components
* formData.js: Shows all the form details int the format of the output to be printed.
* invoiceForm.js: form to accept all the details from the user.
* invoiceTable.js: Contains the format of the table data to be integrated in formData.js.
* signature.js: Components accepts signature from the user as input to be printed in the output(integrated in formData.js).
* totalAmount.js: Provides the totalamount in numbers and in words to be shown in output(integrated in formData.js).

* calculate.js: component to calculates the totalAmount, netamount.
* currToWords.js : converts ruppees in numbers to words.

* itemsValidate.js: validates that there is no null value or invalid entry in the items table.

