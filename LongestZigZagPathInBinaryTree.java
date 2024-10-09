// Problem Link (Leetcode Problem) : https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/description

//Solution
class Solution {
    public int longestZigZag(TreeNode root) {
        return Math.max(helper(root.left, 'l', 0), helper(root.right, 'r', 0));
    }

    public static int helper(TreeNode root, char prevDir, int length){
        if(root == null){
            return length;
        }

        int maxZigZag = 0;

        if(prevDir == 'l'){
            maxZigZag = helper(root.right, 'r', length+1);

            maxZigZag = Math.max(maxZigZag, helper(root.left, 'l', 0));
        }
        else if(prevDir == 'r'){
            maxZigZag = helper(root.left, 'l', length+1);

            maxZigZag = Math.max(maxZigZag, helper(root.right, 'r', 0));
        }

        return maxZigZag;
    }
}
