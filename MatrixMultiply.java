public class Solution {
    public int[][] solve(int[][] A, int[][] B) {
         int [][] C = new int[A.length][B[0].length];
        
 
        for (int i = 0; i < A.length; i++) {
            for (int j = 0; j < B[0].length; j++) {
                for (int k = 0; k < A[0].length; k++) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }

        return C;
    }
}
