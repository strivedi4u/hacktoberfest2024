/**
 * Solution class provides a method to calculate the amount of trapped rainwater
 * given an array representing elevation heights.
 */
class Solution {

    /**
     * Calculates the total amount of trapped rainwater using a two-pointer approach.
     *
     * @param height An array of integers where each element represents the height of an elevation.
     * @return The total units of water that can be trapped after raining.
     */
    public int trap(int[] height) {
        // Edge case: If height array is null or has less than 3 elements, no water can be trapped.
        if (height == null || height.length <= 2) {
            return 0;
        }

        // Initialize two pointers, left starting at the beginning and right at the end of the height array.
        int left = 0;
        int right = height.length - 1;

        // Variables to track the maximum height encountered from the left and right pointers, respectively.
        int leftMax = 0;
        int rightMax = 0;

        // Variable to accumulate the total trapped water.
        int water = 0;

        // Continue until the left and right pointers meet.
        while (left < right) {
            // Update leftMax and rightMax based on the current heights.
            leftMax = Math.max(leftMax, height[left]);
            rightMax = Math.max(rightMax, height[right]);

            // Determine which side has the smaller maximum height.
            if (leftMax < rightMax) {
                // Water trapped at the left pointer depends on the difference between leftMax and height[left].
                water += leftMax - height[left];
                // Move the left pointer to the right.
                left++;
            } else {
                // Water trapped at the right pointer depends on the difference between rightMax and height[right].
                water += rightMax - height[right];
                // Move the right pointer to the left.
                right--;
            }
        }

        // Return the total trapped water.
        return water;
    }
}