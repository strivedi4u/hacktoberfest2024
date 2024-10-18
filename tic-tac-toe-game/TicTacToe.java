import java.util.Scanner;

public class TicTacToe {
    // Set up the game board as an array
    static String[] board = {"-", "-", "-", "-", "-", "-", "-", "-", "-"};

    // Define a function to print the game board
    static void printBoard() {
        System.out.println(board[0] + " | " + board[1] + " | " + board[2]);
        System.out.println(board[3] + " | " + board[4] + " | " + board[5]);
        System.out.println(board[6] + " | " + board[7] + " | " + board[8]);
    }

    // Define a function to handle a player's turn
    static void takeTurn(String player) {
        Scanner scanner = new Scanner(System.in);
        System.out.println(player + "'s turn.");
        System.out.print("Choose a position from 1-9: ");
        int position = scanner.nextInt() - 1;
        while (position < 0 || position > 8 || !board[position].equals("-")) {
            System.out.print("Invalid input or position already taken. Choose a different position: ");
            position = scanner.nextInt() - 1;
        }
        board[position] = player;
        printBoard();
    }

    // Define a function to check if the game is over
    static String checkGameOver() {
        // Check for a win
        if ((board[0].equals(board[1]) && board[1].equals(board[2]) && !board[0].equals("-")) ||
                (board[3].equals(board[4]) && board[4].equals(board[5]) && !board[3].equals("-")) ||
                (board[6].equals(board[7]) && board[7].equals(board[8]) && !board[6].equals("-")) ||
                (board[0].equals(board[3]) && board[3].equals(board[6]) && !board[0].equals("-")) ||
                (board[1].equals(board[4]) && board[4].equals(board[7]) && !board[1].equals("-")) ||
                (board[2].equals(board[5]) && board[5].equals(board[8]) && !board[2].equals("-")) ||
                (board[0].equals(board[4]) && board[4].equals(board[8]) && !board[0].equals("-")) ||
                (board[2].equals(board[4]) && board[4].equals(board[6]) && !board[2].equals("-"))) {
            return "win";
        }
        // Check for a tie
        else if (!String.join("", board).contains("-")) {
            return "tie";
        }
        // Game is not over
        else {
            return "play";
        }
    }

    // Define the main game loop
    public static void main(String[] args) {
        printBoard();
        String currentPlayer = "X";
        boolean gameOver = false;
        while (!gameOver) {
            takeTurn(currentPlayer);
            String gameResult = checkGameOver();
            if (gameResult.equals("win")) {
                System.out.println(currentPlayer + " wins!");
                gameOver = true;
            } else if (gameResult.equals("tie")) {
                System.out.println("It's a tie!");
                gameOver = true;
            } else {
                // Switch to the other player
                currentPlayer = currentPlayer.equals("X") ? "O" : "X";
            }
        }
    }
}