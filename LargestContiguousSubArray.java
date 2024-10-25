public class LargestContiguousSubArray {

        public static void main(String[] args) {
            int[] array = {-2, -3, 4, -1, 2, 1, -5, -3};
    
            int maxSum = findLargestContiguousSubarraySum(array);
            System.out.println("Largest Contiguous Subarray Sum: " + maxSum);
        }
    
        public static int findLargestContiguousSubarraySum(int[] nums) {
            int currentSum = nums[0];
            int maxSum = nums[0];
    
            for (int i = 1; i < nums.length; i++) {
                // Calculate the maximum of the current element and the sum of the current element and previous sum
                currentSum = Math.max(nums[i], currentSum + nums[i]);
    
                // Update the maximum sum if the current sum is greater
                maxSum = Math.max(maxSum, currentSum);
            }
    
            return maxSum;
        }
    }
    
