let randomNumber = Math.floor(Math.random() * 100) + 1;
let attempts = 0;

document.getElementById('submit').addEventListener('click', function() {
    const guess = Number(document.getElementById('guess').value);
    attempts++;

    if (guess < 1 || guess > 100) {
        document.getElementById('result').innerText = "Please enter a number between 1 and 100.";
    } else if (guess < randomNumber) {
        document.getElementById('result').innerText = "Too low! Try again.";
    } else if (guess > randomNumber) {
        document.getElementById('result').innerText = "Too high! Try again.";
    } else {
        document.getElementById('result').innerText = `Congratulations! You've guessed the number in ${attempts} attempts!`;
        document.getElementById('restart').style.display = 'block';
    }
});

document.getElementById('restart').addEventListener('click', function() {
    randomNumber = Math.floor(Math.random() * 100) + 1;
    attempts = 0;
    document.getElementById('guess').value = '';
    document.getElementById('result').innerText = '';
    document.getElementById('restart').style.display = 'none';
});
