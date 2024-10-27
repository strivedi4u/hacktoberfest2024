import React from 'react';
import { calculateTotal } from '../../utils/calculate';
import { currToWords } from '../../utils/currToWords';
import "./styles.css"
const TotalAmount = ({ data }) => {
    const totalAmount = calculateTotal(data.items, data.sellerDetails, data.shippingDetails);

    let words = currToWords(totalAmount.total)

    return (
        <>
            <tr className='total'>

                <td className='text-start' colSpan="7">
                    Total
                </td>
                <td>{totalAmount.tax}</td>
                <td>{totalAmount.total}</td>
            </tr>
            <tr className='totalwords' >

                <td colSpan="9" className=' text-start'>

                    <strong>
                        Amount in words: <br />
                    </strong>
                    {words}
                </td>
            </tr>
        </>
    );
};

export default TotalAmount;
