import java.util.Arrays;

public class LargestElementFinder {

    public static int findLargestElement(int[] arr) {
        if (arr.length == 0) {
            throw new IllegalArgumentException("Array is empty.");
        }

        int largest = arr[0]; // Assume the first element is the largest

        // Iterate through the array to find the largest element
        for (int num : arr) {
            if (num > largest) {
                largest = num; // Update largest if current element is greater
            }
        }

        return largest; // Return the largest element found
    }

    public static void main(String[] args) {
        int[] arr = {10, 5, 20, 8};
        int largestElement = findLargestElement(arr);

        System.out.println("The largest element in the array is: " + largestElement);
    }
}
