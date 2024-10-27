export const itemValidate = (items) => {
    let formErrors = {};
    let isValid = true;

    items.forEach((item, index) => {
        if (!item.description.trim()) {
            formErrors[`item-description-${index}`] = "Item description is required";
            isValid = false;
        }
        if (item.quantity <= 0 || isNaN(item.quantity)) {
            formErrors[`item-quantity-${index}`] = "Quantity must be greater than 0";
            isValid = false;
        }
        if (item.unitPrice <= 0 || isNaN(item.unitPrice)) {
            formErrors[`item-unitPrice-${index}`] = "Unit Price must be greater than 0";
            isValid = false;
        }
        if (item.discount < 0 || isNaN(item.discount)) {
            formErrors[`item-discount-${index}`] = "Discount must be 0 or greater";
            isValid = false;
        }
    });

    return { isValid, formErrors };
};

