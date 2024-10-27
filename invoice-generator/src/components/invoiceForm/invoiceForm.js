import React, { useState } from 'react';
import { calculateNetAmount } from '../../utils/calculate';
import "./styles.css";
import { itemValidate } from '../../utils/itemValidate';

const InvoiceForm = ({ onSubmit }) => {
    const [errors, setErrors] = useState({});

    const [sellerDetails, setSellerDetails] = useState({
        name: '',
        address: '',
        pan: '',
        gst: '',
        supply: '',
    });

    const [billingDetails, setBillingDetails] = useState({
        name: '',
        address: '',
        code: '',
    })

    const [shippingDetails, setShippingDetails] = useState({
        name: '',
        address: '',
        code: '',
        place: '',
    });
    const [orderDetails, setOrderDetails] = useState({
        num: "",
        date: "",
    });
    const [invoiceDetails, setInvoiceDetails] = useState({
        number: '',
        details: '',
        date: "",
    });

    const [items, setItems] = useState([
        { description: '', quantity: 1, unitPrice: 0, discount: 0, taxRate: 0 },
    ]);

    // For setting seller details
    const handleSellerChange = (e) => {
        setSellerDetails({
            ...sellerDetails,
            [e.target.name]: e.target.value,
        });
    };
    // For setting Billing details
    const handleBillingChange = (e) => {
        setBillingDetails({
            ...billingDetails,
            [e.target.name]: e.target.value,
        });
    };
    // For setting shipping details
    const handleShippingChange = (e) => {
        setShippingDetails({
            ...shippingDetails,
            [e.target.name]: e.target.value,
        });
    };
    // For setting order details
    const handleOrderChange = (e) => {
        const { name, value } = e.target;

        if (name == "date") {
            const formattedDate = new Date(value).toLocaleDateString('en-GB'); // Format as dd/mm/yyyy
            setOrderDetails({
                ...orderDetails,
                [name]: formattedDate,
            });
        } else {
            setOrderDetails({
                ...orderDetails,
                [name]: value,
            });
        }
    };
    // For setting invoice details
    const handleInvoiceChange = (e) => {
        const { name, value } = e.target;
        if (name == "date") {
            const formattedDate = new Date(value).toLocaleDateString('en-GB');
            setInvoiceDetails({
                ...invoiceDetails,
                [name]: formattedDate,
            });
        } else {
            setInvoiceDetails({
                ...invoiceDetails,
                [name]: value,
            });
        }
    };

    // For setting item details
    const handleItemChange = (index, field, value) => {
        const newItems = [...items];
        newItems[index][field] = value;
        setItems(newItems);
    };

    // For addming more item
    const handleAddItem = () => {
        const val = itemValidate(items);
        if (val.isValid) {

            setItems([...items, { description: '', quantity: 1, unitPrice: 0, discount: 0, taxRate: 18 }]);
            setErrors('');
        } else {
            setErrors(val.formErrors);
        }
    };

    // For submitting the form and returning the values to state variable in app.js
    const handleSubmit = (e) => {
        e.preventDefault();
        onSubmit({ sellerDetails, billingDetails, shippingDetails, orderDetails, invoiceDetails, items });
    };

    return (
        <div className="container w-75 p-4 my-5 shadow rounded-2">
            <div className='d-flex justify-content-center'>

                <h1>
                    Invoice Form
                </h1>
            </div>
            <form onSubmit={handleSubmit} className=''>
                <div className="entered-details form-group d-flex flex-column ">
                    <h3 className='text-start py-3'>Seller Details</h3>
                    <div className='d-flex col-12 flex-grow-1 justify-content-between'>
                        <div className="col-lg-3 ">

                            <input type="text" className='' required name="name" placeholder="Seller Name" value={sellerDetails.name} onChange={handleSellerChange} />
                        </div>
                        <div className="col-lg-3 ">
                            <input type="text" className='' required name="address" placeholder="Address" value={sellerDetails.address} onChange={handleSellerChange} />

                        </div>
                        <div className="col-lg-3  ">
                            <input type="text" maxLength="10" required className='' name="pan" placeholder="PAN Number" value={sellerDetails.pan} onChange={handleSellerChange} />

                        </div>
                        <div className="col-lg-3  ">

                            <input type="text" className='' required name="gst" placeholder="GST Number" value={sellerDetails.gst} onChange={handleSellerChange} />
                        </div>
                        <br />
                    </div>
                    <div className="col-lg-3 mt-3 ">

                        <input type="text" className='' required name="supply" placeholder="Place of Supply" value={sellerDetails.supply} onChange={handleSellerChange} />
                    </div>
                </div>
                <h3 className='text-start py-3'>Billing Details</h3>
                <div className='d-flex flex-grow-1 justify-content-between'>
                    <div className="col-4 ">

                        <input type="text" name="name" className='  required     h-100' placeholder="Billing Name" value={billingDetails.name} onChange={handleBillingChange} />
                    </div>
                    <div className="col-4 ">

                        <input type="text" name="address" className='' required placeholder="Address" value={billingDetails.address} onChange={handleBillingChange} />
                    </div>
                    <div className="col-4 ">

                        <input type="number" min="0" name="code" className='' required placeholder="State/UT code" value={billingDetails.pan} onChange={handleBillingChange} />
                    </div>
                </div>
                <h3 className='text-start py-3'>Shipping Details</h3>
                <div className=' d-flex justify-content-between'>
                    <div className="col-3 ">

                        <input type="text" name="name" className='' required placeholder="Shipping Name" value={shippingDetails.name} onChange={handleShippingChange} />
                    </div>
                    <div className="col-3 ">

                        <input type="text" name="address" className='' required placeholder="Address" value={shippingDetails.address} onChange={handleShippingChange} />
                    </div>
                    <div className="col-3 ">

                        <input type="number" name="code" min="0" className='' required placeholder="State/UT code" value={shippingDetails.code} onChange={handleShippingChange} />
                    </div>
                    <div className="col-3 ">

                        <input type="text" name="place" className='' required placeholder="Place of Delivery" value={shippingDetails.place} onChange={handleShippingChange} />
                    </div>
                </div>
                <h3 className='text-start py-3'>Order Details</h3>
                <div className='d-flex justify-content-between'>
                    <div className="col-6 ">
                        <input type="number" name="num" min="0" className='' required placeholder="Order number" value={orderDetails.num} onChange={handleOrderChange} />

                    </div>
                    <div className="col-6">

                        <input type="date" name="date" className='' placeholder="Order date" value={orderDetails.date} onChange={handleOrderChange} />
                    </div>
                </div>
                <h3 className='text-start py-3'>Invoice Details</h3>
                <div className=' d-flex justify-content-between'>
                    <div className="col-4 ">


                        <input type="number" name="number" className='' required placeholder="Invoice number" value={invoiceDetails.number} onChange={handleInvoiceChange} />
                    </div>
                    <div className="col-4 ">

                        <input type="text" name="details" className='' required placeholder="Invoice Details" value={invoiceDetails.details} onChange={handleInvoiceChange} />
                    </div>
                    <div className="col-4 ">

                        <input type="date" name="date" className='' placeholder="date" value={invoiceDetails.date} onChange={handleInvoiceChange} />
                    </div>
                </div>
                <h3 className='mt-3'>Items</h3>
                <table className=' table table-bordered'>
                    <thead>
                        <tr>
                            <th scope='col'>Description</th>
                            <th scope='col'>Quantity</th>
                            <th scope='col'>Unit Price </th>
                            <th scope='col'>Discount %</th>
                            <th scope='col'>Net Amount</th>
                            <th scope='col'></th>
                        </tr>
                    </thead>

                    <tbody>

                        {items.map((item, index) => {
                            const netamt = calculateNetAmount(item.unitPrice, item.quantity, item.discount)
                            return (
                                <tr key={index}>
                                    <td>

                                        <input type="text" placeholder="Description" className='' value={item.description} onChange={(e) => handleItemChange(index, 'description', e.target.value)} />
                                        <div className='d-flex justify-content-center'>

                                            {errors[`item-description-${index}`] && (
                                                <span className="error">{errors[`item-description-${index}`]}</span>
                                            )}
                                        </div>
                                    </td >
                                    <td>

                                        <input type="number" min="0" placeholder="Quantity" className='' value={item.quantity} onChange={(e) => handleItemChange(index, 'quantity', e.target.value)} />
                                        <div className='d-flex justify-content-center'>

                                            {errors[`item-quantity-${index}`] && (
                                                <span className="error">{errors[`item-quantity-${index}`]}</span>
                                            )}
                                        </div>
                                    </td>
                                    <td>

                                        <input type="number" min="0" placeholder="Unit Price" className='' value={item.unitPrice} onChange={(e) => handleItemChange(index, 'unitPrice', e.target.value)} />
                                        <div className='d-flex justify-content-center'>

                                            {errors[`item-description-${index}`] && (
                                                <span className="error">{errors[`item-unitPrice-${index}`]}</span>
                                            )}
                                        </div>
                                    </td>
                                    <td>

                                        <input type="number" min="0" placeholder="Discount" className='' value={item.discount} onChange={(e) => handleItemChange(index, 'discount', e.target.value)} />
                                        <div className='d-flex justify-content-center'>

                                            {errors[`item-discount-${index}`] && (
                                                <span className="error">{errors[`item-discount-${index}`]}</span>
                                            )}
                                        </div>
                                    </td>
                                    <td>

                                        <input type="number" placeholder="netamt" className='' value={netamt} disabled />

                                    </td>

                                </tr>
                            )
                        })}
                    </tbody>

                </table>
                <div className='d-flex justify-content-center'>

                    <button className='add rounded-1 p-2' type="button" onClick={handleAddItem}>Add More Item</button>
                </div>
                <div className='my-4 d-flex justify-content-center '>

                    <button className='generate rounded-1 p-2 w-25' type="submit">Generate Invoice</button>
                </div>
            </form>
        </div >
    );
};

export default InvoiceForm;
