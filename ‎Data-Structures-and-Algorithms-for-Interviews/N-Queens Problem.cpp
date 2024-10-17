#include<bits/stdc++.h>
using namespace std;

// Recursive function to place queens on the board
void func(int col, int n, vector<vector<string>>& ans, vector<string>& board, vector<int>& left, vector<int>& lowerdiagonal, vector<int>& upperdiagonal){
  if(col==n){ // If we have successfully placed queens in all columns, add the current board configuration to the answer
    ans.push_back(board);
    return;
  }
  // Try placing a queen in each row of the current column
  for(int row=0;row<n;row++){
    // Check if it's safe to place a queen at (row, col)
    // 1) Check if there is no queen in the current row (left[row])
    // 2) Check if there is no queen in the current lower diagonal (lowerdiagonal[row + col])
    // 3) Check if there is no queen in the current upper diagonal (upperdiagonal[(n - 1) + (col - row)])
    if(left[row]==0 && lowerdiagonal[row+col]==0 && upperdiagonal[(n-1) + (col-row)]==0){
      // Place the queen on the board
      board[row][col]='Q';
      // Mark the row, lower diagonal, and upper diagonal as attacked
      left[row] = 1;
      lowerdiagonal[row+col] = 1;
      upperdiagonal[(n-1) + (col-row)] = 1;
      // Recur to place a queen in the next column
      func(col+1,n,ans,board,left,lowerdiagonal,upperdiagonal);

      // Backtrack: remove the queen and unmark the attacked positions
      board[row][col]='.';
      left[row] = 0;
      lowerdiagonal[row+col] = 0;
      upperdiagonal[(n-1) + (col-row)] = 0;
    }
  }
}

// Main function to solve the N-Queens problem
vector<vector<string>> solveNQueens(int n) {
  vector<vector<string>> ans; // Stores all valid solutions 
  vector<string> board(n); // Current board configuration
  // Initialize the board with '.' (empty spaces)
  string s(n,'.');
  for(int i=0;i<n;i++){
    board[i] = s;
  }
  // Vectors to keep track of attacked rows, lower diagonals, and upper diagonals
  vector<int> left(n,0), lowerdiagonal(2*n-1,0), upperdiagonal(2*n-1,0);
  // Start the recursion from the first column
  func(0,n,ans,board,left,lowerdiagonal,upperdiagonal);
  return ans;
}

int main(){
  int n; // Input the size of the board (n x n)
  cin>>n;
  vector<vector<string>> ans = solveNQueens(n);
  // Optionally print all solutions (for testing purposes)
  for(auto it : ans) {
    for(auto row : it) {
      cout << row << endl;
    }
    cout << endl;
  }
  return 0;
}
