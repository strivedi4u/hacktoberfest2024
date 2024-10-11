/*
The Zigzag Conversion problem involves taking a given string s and
converting it into a zigzag pattern on a grid with numRows rows.
The string is written row by row, starting from the top, and then read line by line to produce the final output string.
*/


import java.util.*;

class Solution {
    public String convert(String s, int numRows) {
        if (numRows == 1)
            return s;
        StringBuilder ret = new StringBuilder();
        for (int r=0; r<numRows; r++){
            int inc = 2 * (numRows - 1);
            for (int i=r; i<s.length(); i+=inc){
                ret.append(s.charAt(i));
                if (r > 0 && r < numRows-1 && i+inc-2*r < s.length()){
                    ret.append(s.charAt(i+inc-2*r));
                }
            }
        }
        return new String(ret);
    }
}


public class Zigazag_Pattern {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        Solution sol = new Solution();
        System.out.print("Enter the string: ");
        String s = in.nextLine();
        System.out.print("Enter the number of rows: ");
        int numRows = in.nextInt();
        System.out.println(sol.convert(s, numRows));
        in.close();
    }
}