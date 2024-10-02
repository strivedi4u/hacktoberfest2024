#include <iostream>
#include <vector>

int search(const std::vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if we found the target
        if (nums[mid] == target) {
            return mid;
        }

        // Check which side is sorted
        if (nums[left] <= nums[mid]) {
            // Left side is sorted
            if (nums[left] <= target && target < nums[mid]) {
                right = mid - 1; // Search in the left half
            } else {
                left = mid + 1; // Search in the right half
            }
        } else {
            // Right side is sorted
            if (nums[mid] < target && target <= nums[right]) {
                left = mid + 1; // Search in the right half
            } else {
                right = mid - 1; // Search in the left half
            }
        }
    }

    return -1; // Target not found
}

int main() {
    std::vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    int result = search(nums, target);

    if (result != -1) {
        std::cout << "Target found at index: " << result << std::endl;
    } else {
        std::cout << "Target not found." << std::endl;
    }

    return 0;
}
