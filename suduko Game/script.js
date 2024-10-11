// script.js

// Initialize and create the Sudoku grid
function createGrid() {
    const board = document.getElementById('sudoku-board');
    for (let i = 0; i < 81; i++) {
        const input = document.createElement('input');
        input.type = 'number';
        input.min = '1';
        input.max = '9';
        board.appendChild(input);
    }
}

// Get the board as a 2D array from the input fields
function getBoard() {
    const inputs = document.querySelectorAll('#sudoku-board input');
    const board = [];
    let row = [];
    inputs.forEach((input, index) => {
        const value = input.value ? parseInt(input.value) : 0;
        row.push(value);
        if (row.length === 9) {
            board.push(row);
            row = [];
        }
    });
    return board;
}

// Set the board back to the input fields from a 2D array
function setBoard(board) {
    const inputs = document.querySelectorAll('#sudoku-board input');
    inputs.forEach((input, index) => {
        const row = Math.floor(index / 9);
        const col = index % 9;
        input.value = board[row][col] || '';
    });
}

// Solve Sudoku using backtracking
function solveSudoku() {
    const board = getBoard();
    if (solve(board)) {
        setBoard(board);
    } else {
        alert("No solution exists for the given Sudoku.");
    }
}

// Helper function to check if a number is valid in a position
function isValid(board, num, row, col) {
    for (let i = 0; i < 9; i++) {
        if (board[row][i] === num || board[i][col] === num) {
            return false;
        }
        const boxRow = 3 * Math.floor(row / 3) + Math.floor(i / 3);
        const boxCol = 3 * Math.floor(col / 3) + (i % 3);
        if (board[boxRow][boxCol] === num) {
            return false;
        }
    }
    return true;
}

// Recursive backtracking function
function solve(board) {
    for (let row = 0; row < 9; row++) {
        for (let col = 0; col < 9; col++) {
            if (board[row][col] === 0) {
                for (let num = 1; num <= 9; num++) {
                    if (isValid(board, num, row, col)) {
                        board[row][col] = num;
                        if (solve(board)) {
                            return true;
                        }
                        board[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

// Initialize grid on page load
window.onload = createGrid;
