#include <iostream>
#include <vector>

int findLargestElement(const std::vector<int>& arr) {
    if (arr.empty()) {
        std::cerr << "Array is empty." << std::endl;
        return -1; // Return an error code
    }

    int largest = arr[0]; // Assume the first element is the largest

    // Iterate through the array to find the largest element
    for (const int& num : arr) {
        if (num > largest) {
            largest = num; // Update largest if current element is greater
        }
    }
    
    return largest; // Return the largest element found
}

int main() {
    std::vector<int> arr = {10, 5, 20, 8};
    int largestElement = findLargestElement(arr);

    std::cout << "The largest element in the array is: " << largestElement << std::endl;

    return 0;
}
