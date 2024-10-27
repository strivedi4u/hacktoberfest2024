import React, { useState } from 'react';
import "./styles.css"

const Signature = ({ data }) => {
    const { sellerDetails } = data;
    const [signatureImage, setSignatureImage] = useState('');

    const handleImageUpload = (event) => {
        const file = event.target.files[0];
        if (file) {
            const reader = new FileReader();
            reader.onloadend = () => {
                setSignatureImage(reader.result);
            };
            reader.readAsDataURL(file);
        }
    };

    return (
        <td colSpan="9" className='text-end'>

            <div className='company-name'>

                <strong>For {sellerDetails.name}</strong>
            </div>

            {!signatureImage && (
                <div className='sign d-flex justify-content-end'>

                    <input
                        type="file"
                        accept="image/*"
                        onChange={handleImageUpload}
                    />
                </div>
            )
            }
            {signatureImage && (
                <div>
                    <p><img src={signatureImage} alt="Signature" style={{ width: '200px' }} /></p>
                </div>
            )}



            <p> <strong className='auth'>
                Authorized Signatory
            </strong>
            </p>
        </td>
    );
};

export default Signature;
