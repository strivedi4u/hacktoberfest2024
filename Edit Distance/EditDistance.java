// Problem
/* 
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

-> Insert a character
-> Delete a character
-> Replace a character
*/

public class EditDistance {
        public static int minDistance(String word1, String word2) {
            int n=word1.length();
            int m=word2.length();
            int[][] dp = new int[n+1][m+1];
            for(int  i= 0 ; i<n+1 ;i++){
                for(int j=0 ;j<m+1 ; j++){
                    if(i==0) dp[i][j] = j;
                    if(j==0) dp[i][j]= i;
                }
            }

            for(int i=1 ; i<n+1 ; i++){
                for(int j=1; j<m+1 ; j++){
                    if(word1.charAt(i-1)==word2.charAt(j-1)) dp[i][j]=dp[i-1][j-1];
                    else{
                        int insert=dp[i][j-1]+1;
                        int delete = dp[i-1][j]+1;
                        int replace = dp[i-1][j-1]+1;
                        dp[i][j]=Math.min(insert,Math.min(delete,replace));
                    }
                }
            }

            return dp[n][m];
        }

    public static void main(String[] args) {
        
//            Test Case 1
        int test1 = minDistance("horse","ros");
        System.out.println(test1);

//        Output :3
//        horse -> rorse (replace 'h' with 'r')
//        rorse -> rose (remove 'r')
//        rose -> ros (remove 'e')


//        Test Case 2
        int test2= minDistance("intention","execution");
        System.out.println(test2);

//        Output :5
//        intention -> inention (remove 't')
//        inention -> enention (replace 'i' with 'e')
//        enention -> exention (replace 'n' with 'x')
//        exention -> exection (replace 'n' with 'c')
//        exection -> execution (insert 'u')

    }

}
