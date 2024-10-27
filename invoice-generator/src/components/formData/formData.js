import React from 'react'
import "./styles.css"

const FormData = ({ data }) => {
    console.log(data);
    const { sellerDetails, invoiceDetails, orderDetails, billingDetails, shippingDetails } = data;
    console.log(sellerDetails, billingDetails);




    return (
        <div className='formData-container mt-2'>
            <div className="col-12 d-flex justify-content-between ">

                <img src="https://upload.wikimedia.org/wikipedia/commons/a/a9/Amazon_logo.svg" alt="Amazon Logo" style={{ width: '100px' }} />

                <div className="d-flex flex-column align-items-end">
                    <h5>Tax Invoice/Bill of Supply/Cash Memo</h5>
                    <small>(Original for Recipient)</small>
                </div>
            </div>

            <div className="row mt-5 ">
                <div className='col-6'>
                    <p className='text-start w-75'><strong>
                        Sold By : <br />
                    </strong>
                        {sellerDetails.address ? sellerDetails.address : `Varasiddhi Silk Exports
                        75, 3rd Cross, Lalbagh Road
                        Bengaluru, Karnataka, 560027`}
                    </p>
                </div>
                <div className='col-6 d-flex justify-content-end'>
                    <p className='text-end w-75'>
                        <strong>
                            Billing Address : <br />
                        </strong>

                        {billingDetails.address ? sellerDetails.address : ` Madhu B
                        Eurofins IT Solutions India Pvt Ltd
                        1st Floor, Maruti Platinum, AECS Layout, Bengaluru, Karnataka, 560037
                       `}
                    </p>
                </div>
            </div>
            <div className="row mt-1">
                <div className='col-6 w-50'>
                    <p className='text-start w-50'>
                        <strong>
                            PAN No:
                        </strong>
                        {sellerDetails.pan ? sellerDetails.pan : `AACFV3325K`}
                        <br />

                        <strong>
                            GST Registration No:

                        </strong>
                        {sellerDetails.pan ? sellerDetails.gst : `29AACFV3325K1ZY`}

                    </p>
                </div>
                <div className='col-6 d-flex justify-content-end'>
                    <p className='text-end w-75'>
                        <strong>
                            State/UT Code:
                        </strong>
                        {billingDetails.code ? billingDetails.code : `AACFV3325K`}

                    </p>
                </div>
            </div>

            <div className="row mt-0">
                <div className='col-6 d-flex align-items-end'>
                    <p className='text-start w-50'><strong>


                        Order Number:
                    </strong>
                        {orderDetails.num ? orderDetails.num : `AACFV3325K`}
                        <br />
                        <strong>

                            Order Date:
                        </strong>
                        {orderDetails.date}


                    </p>
                </div>
                <div className='col-6 d-flex justify-content-end'>
                    <p className='text-end text-justify w-75'><strong>

                        Shipping Address : <br />
                    </strong>
                        {shippingDetails.address ? shippingDetails.address : `Madhu B
                        Eurofins IT Solutions India Pvt Ltd
                        1st Floor, Maruti Platinum, AECS Layout, Bengaluru, Karnataka, 560037
                       `}
                        <br />
                        <strong>
                            State/UT Code:
                        </strong>
                        {shippingDetails.code ? shippingDetails.code : `hghjk`}


                        <br />
                        <strong>
                            Place of Supply:
                        </strong>
                        {shippingDetails.place ? shippingDetails.place : ` KARNATAKA`}


                        <br />
                        <strong>
                            Place of Delivery:
                        </strong>
                        {shippingDetails.place ? shippingDetails.place : ` KARNATAKA`}

                        <br />
                        <strong>
                            Invoice Number:
                        </strong>
                        {invoiceDetails.number ? invoiceDetails.number : ` tuioi;p`}


                        <br />
                        <strong>

                            Invoice Details:
                        </strong>
                        {invoiceDetails.details ? invoiceDetails.details : ` hgfhg`}


                        <br />
                        <strong>
                            Invoice Date:
                        </strong>
                        {invoiceDetails.date}
                    </p>
                </div>
            </div>
        </div >

    )
}

export default FormData;