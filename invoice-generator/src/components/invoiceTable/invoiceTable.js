import React from 'react';
import { calculateNetAmount, calculateTax, calculateTaxAmount } from '../../utils/calculate';
import "./styles.css";
import TotalAmount from "../totalAmount/totalAmount.js";
import Signature from "../signature/signature.js";

const InvoiceTable = ({ data }) => {

    const { sellerDetails, shippingDetails, items } = data;

    return (
        <div className="invoiceTable-container">
            <table className="table-custom-bordered">
                <thead>
                    <tr>
                        <th>S no.</th>
                        <th>Description</th>
                        <th>Unit Price</th>
                        <th>Quantity</th>
                        <th>Discount</th>
                        <th>Net Amount</th>
                        <th>Tax Type</th>
                        <th>Tax Amount</th>
                        <th>Total Amount</th>
                    </tr>
                </thead>
                <tbody>
                    {items.map((item, index) => {
                        const netAmount = calculateNetAmount(item.unitPrice, item.quantity, item.discount);
                        const taxrate = calculateTax(sellerDetails, shippingDetails);
                        const taxAmount = calculateTaxAmount(taxrate, netAmount);

                        return (
                            <tr key={index}>
                                <td width="2%">{index + 1}</td>
                                <td width="50%">{item.description}</td>
                                <td>{item.unitPrice}</td>
                                <td>{item.quantity}</td>
                                <td>{item.discount}</td>
                                <td>{netAmount}</td>
                                <td width="5%">{taxrate[0]} <br />
                                    {taxrate[1]}
                                </td>
                                <td width="5%"> {(taxrate.length == 2) ? (<div>{taxAmount[0]}<br /> {taxAmount[1]}</div>) : (taxAmount[0])}
                                </td>
                                <td width="5%"> {(taxrate.length == 2) ? (<div>{taxAmount[0] + netAmount}<br /> {taxAmount[1] + netAmount}</div>) : (taxAmount[0])}
                                </td>

                            </tr>
                        );
                    })}

                    <TotalAmount data={data} />
                    <tr>
                        <Signature data={data} />
                    </tr>
                </tbody>
            </table>
        </div>
    );
};

export default InvoiceTable;
