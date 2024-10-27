import React, { useState, useRef } from 'react';
import InvoiceTable from './components/invoiceTable/invoiceTable.js';
import InvoiceForm from './components/invoiceForm/invoiceForm.js';
import FormData from './components/formData/formData.js';
import { useReactToPrint } from 'react-to-print';
import "./App.css"

// Kindly read the README.md file for the whole informationa and working of the project

function App() {
  const [invoiceData, setInvoiceData] = useState(null);
  const componentRef = useRef();

  const handleSubmit = (data) => {
    setInvoiceData(data);
  };

  const handlePrint = useReactToPrint({
    content: () => componentRef.current,
  });

  return (
    <div className="App">
      {!invoiceData ? (
        <InvoiceForm onSubmit={handleSubmit} />
      ) : (
        <div className=' my-5'>
          <div ref={componentRef}>
            <FormData data={invoiceData} />
            <div >
              <InvoiceTable data={invoiceData} />

            </div>
          </div>
          <div className='d-flex justify-content-center pt-5'>

            <button className='print p-3 rounded-2 ' onClick={handlePrint}>Print or Download PDF</button>
          </div>
        </div>
      )}
    </div>
  );
}

export default App;
