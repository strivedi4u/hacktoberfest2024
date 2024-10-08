import java.util.*;
public class SudokuSolver {
    public static void main(String[] args) {
        int[][] board1 = new int[][] {
            {5, 3, 0, 0, 7, 0, 0, 0, 0},
            {6, 0, 0, 1, 9, 5, 0, 0, 0},
            {0, 9, 8, 0, 0, 0, 0, 6, 0},
            {8, 0, 0, 0, 6, 0, 0, 0, 3},
            {4, 0, 0, 8, 0, 3, 0, 0, 1},
            {7, 0, 0, 0, 2, 0, 0, 0, 6},
            {0, 6, 0, 0, 0, 0, 2, 8, 0},
            {0, 0, 0, 4, 1, 9, 0, 0, 5},
            {0, 0, 0, 0, 8, 0, 0, 7, 9}
        };
        if(sudokuSolver(board1)) {
            display2(board1);
        } else {
            System.out.println("No solution exists");
        }
    }
    static boolean sudokuSolver(int[][] board) {
        int n = board.length;
        int row=-1;
        int col=-1;
        boolean emptyleft = true;
        //this is how we are replacing the row and column from arguments
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j]==0) {
                    row = i;
                    col = j;
                    emptyleft = false;
                    break;
                }
            }
            //if we found the empty cell
            if(emptyleft==false) {
                break;
            }
        }
        if(emptyleft == true) {
            return true;
            //sudoku is solved
        }
        //backtrack
        for(int num=1; num<=n; num++) {
            if(isSafe2(board, row, col, num)) {
                board[row][col] = num;
                if(sudokuSolver(board)) {
                    //found the solution
                    display2(board);
                    return true;
                } else {
                    //backtrack
                    board[row][col] = 0;
                }
            }
        }
        return false;
    }
    static boolean isSafe2(int[][] board, int row, int col, int num) {
        //check the row and column
        for(int i=0; i<board.length; i++) {
            if(board[row][i]==num || board[i][col]==num) {
                return false;
            }
        }
        int sqrt = (int)Math.sqrt(board.length);
        int startRow = row - row%sqrt;
        int startCol = col - col%sqrt;
        for(int i=startRow; i<startRow+sqrt; i++) { 
            for(int j=startCol; j<startCol+sqrt; j++) {
                if(board[i][j]==num) {
                    return false;
                }
            }
        }
        return true;
    }
    static void display2(int[][] board) {
        for(int[] row: board) {
            for(int element: row) {
                System.out.print(element + " ");
            }
            System.out.println();
        }
    }
}