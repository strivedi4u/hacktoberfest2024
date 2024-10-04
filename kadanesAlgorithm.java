import java.util.Scanner;

class KadanesAlgorithm {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the size of the array:");
        int n = sc.nextInt();
        
        int[] arr = new int[n];
        System.out.println("Enter the elements of the array:");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        
        int maxSum = kadanesAlgorithm(arr);
        System.out.println("The maximum sum of a contiguous subarray is: " + maxSum);
        sc.close();
    }

    public static int kadanesAlgorithm(int[] arr) {
        int maxCurrent = arr[0];
        int maxGlobal = arr[0];
        
        for (int i = 1; i < arr.length; i++) {
            maxCurrent = Math.max(arr[i], maxCurrent + arr[i]);
            if (maxCurrent > maxGlobal) {
                maxGlobal = maxCurrent;
            }
        }
        
        return maxGlobal;
    }
}
