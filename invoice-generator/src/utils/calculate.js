export const calculateNetAmount = (unitPrice, quantity, discount) => {
    return unitPrice * quantity - discount;
};

export const calculateTax = (sellerDetails, shippingDetails) => {
    let cgst = 0, sgst = 0;
    if (sellerDetails.supply == shippingDetails.place) {
        cgst = 9;
        sgst = 9;
        return ["CGST", "SGST"];
    }
    else {
        return ["IGST"];
    }

}

export const calculateTaxAmount = (taxrate, netAmount) => {

    if (taxrate.length == 2) {
        let val1 = netAmount * 9 / 100;
        let val2 = netAmount * 9 / 100;

        return [val1, val2];
    }
    else {
        let val1 = netAmount * 18 / 100;
        return [val1];
    }

}


export const calculateTotal = (items, sellerDetails, shippingDetails) => {
    let total = 0;
    let tax = 0;
    const taxrate = calculateTax(sellerDetails, shippingDetails);
    items.forEach(item => {
        const netAmount = calculateNetAmount(item.unitPrice, item.quantity, item.discount);
        const taxAmount = calculateTaxAmount(taxrate, netAmount);
        // const itemTax = netAmount * item.taxRate / 100;
        taxAmount.length == 2 ? total += taxAmount[0] + taxAmount[1] : total += taxAmount[0];
        console.log(total);

        tax = total;
        console.log(tax);

        total += netAmount;
    });

    return { total, tax };
};
