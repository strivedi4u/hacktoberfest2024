using System;

class Program
{
    static void Main(string[] args)
    {
        int[] arr = { 10, 5, 20, 8 };
        try
        {
            int largestElement = FindLargestElement(arr);
            Console.WriteLine("The largest element in the array is: " + largestElement);
        }
        catch (ArgumentException ex)
        {
            Console.WriteLine(ex.Message);
        }
    }

    static int FindLargestElement(int[] arr)
    {
        if (arr.Length == 0)
        {
            throw new ArgumentException("Array is empty.");
        }

        int largest = arr[0]; // Assume the first element is the largest

        // Iterate through the array to find the largest element
        foreach (int num in arr)
        {
            if (num > largest)
            {
                largest = num; // Update largest if current element is greater
            }
        }

        return largest; // Return the largest element found
    }
}
