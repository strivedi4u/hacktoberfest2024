// Get the button element by its ID
const button = document.getElementById("login");

// Add a click event listener to the button
button.addEventListener("click", function() {
    // Set the new URL you want to navigate to
    const newPageURL = "loginpage.html";

    // Navigate to the new page
    window.location.href = newPageURL;
});

// Get the button element by its ID
const button1 = document.getElementById("signup");

// Add a click event listener to the button
button1.addEventListener("click", function() {
    // Set the new URL you want to navigate to
    const newPageURL1 = "signuppage.html";

    // Navigate to the new page
    window.location.href = newPageURL1;
});