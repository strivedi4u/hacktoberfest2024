import java.util.Scanner;
import java.util.Arrays;

public class QuickSort {
     // Partition function
     public static int partition(int[] arr, int low, int high) {
        int pivot = arr[high]; // choosing the last element as pivot
        int i = (low - 1); // index of the smaller element

        for (int j = low; j < high; j++) {
            // If the current element is smaller than or equal to the pivot
            if (arr[j] <= pivot) {
                i++;

                // swap arr[i] and arr[j]
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        // swap arr[i + 1] and arr[high] (or pivot)
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        return i + 1;
    }

    // QuickSort function
    public static void quickSort(int[] arr, int low, int high) {
        if (low < high) {
            // partitionIndex is the partitioning index, arr[partitionIndex] is now at the right place
            int partitionIndex = partition(arr, low, high);

            // Recursively sort elements before and after partition
            quickSort(arr, low, partitionIndex - 1);
            quickSort(arr, partitionIndex + 1, high);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Getting input array size from user
        System.out.print("Enter the number of elements: ");
        int n = scanner.nextInt();

        // Getting the array elements from user
        int[] arr = new int[n];
        System.out.println("Enter the elements:");
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }

        System.out.println("Given Array:");
        System.out.println(Arrays.toString(arr));

        // Sorting the array using Quick Sort
        quickSort(arr, 0, arr.length - 1);

        System.out.println("\nSorted Array:");
        System.out.println(Arrays.toString(arr));

        scanner.close();
    }
    
}



