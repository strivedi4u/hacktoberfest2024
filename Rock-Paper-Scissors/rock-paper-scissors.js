let score = JSON.parse(localStorage.getItem('score')) || {
    wins: 0,
    losses: 0,
    ties: 0
};

updateScoreElement();
/*
if(!score) {
    score = {
        wins: 0,
        losses: 0,
        ties: 0
    };
}
*/

let isautoPlaying = false;
let intervalId;

function autoPlay() {
    if(!isautoPlaying) {
        intervalId = setInterval(() => {
            const computerMove = pickMove();
            playGame(computerMove);
        }, 1000);
        isautoPlaying = true;
    }
    else {
        clearInterval(intervalId);
        isautoPlaying = false;
    }
}

document.querySelector('.js-rock-btn')
    .addEventListener('click', () => {
        playGame('rock');
    });

document.querySelector('.js-paper-btn')
    .addEventListener('click', () => {
        playGame('paper');
    });

document.querySelector('.js-scissors-btn')
    .addEventListener('click', () => {
        playGame('scissors');
    });

document.body.addEventListener('keydown', (event) => {
    if(event.key === 'r')
        playGame('rock');
    else if(event.key === 'p')
            playGame('paper');
    else if(event.key === 's')
            playGame('scissors');
});

function playGame(playerMove)
{
    const computerMove = pickMove();
    let result = '';
    if(playerMove ==='scissors') 
    {
        if(computerMove === 'rock')
            result = 'You lose';
        else if(computerMove === 'paper')
                result = 'You win';
        else if(computerMove === 'scissors')
                result = 'Tie';
    }
    else if(playerMove ==='rock') 
        {
            if(computerMove === 'rock')
                result = 'Tie';
            else if(computerMove === 'paper')
                    result = 'You lose';
            else if(computerMove === 'scissors')
                    result = 'You win';
        }
    else if(playerMove ==='paper') 
        {
            if(computerMove === 'rock')
                result = 'You win';
            else if(computerMove === 'paper')
                    result = 'Tie';
            else if(computerMove === 'scissors')
                    result = 'You lose';
        } 
        
    if(result === 'You win')
        score.wins += 1;
    else if(result === 'You lose')
            score.losses += 1;
    else if(result === 'Tie')
            score.ties += 1;

    localStorage.setItem('score', JSON.stringify(score));

    updateScoreElement();
    document.querySelector('.js-result').innerHTML = result;
    document.querySelector('.js-moves').innerHTML = `You 
    <img src = "./images/${playerMove}-emoji.png" class="move-icon">
    <img src = "./images/${computerMove}-emoji.png" class="move-icon"> 
    Computer`;
}

function updateScoreElement() {
    document.querySelector('.js-score').innerHTML = `Wins: ${score.wins}, Losses: ${score.losses}, Ties: ${score.ties}`;
}

function pickMove() 
{
    const randomNumber = Math.random();
    let computerMove = '';

    if(randomNumber>=0 && randomNumber<1/3)
        computerMove = 'rock';
    else if(randomNumber>=1/3 && randomNumber<2/3)
        computerMove = 'paper';
    else if(randomNumber>=2/3 && randomNumber<1)
        computerMove = 'scissors';
    return computerMove;
}