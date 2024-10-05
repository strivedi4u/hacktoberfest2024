#include <iostream>
#include <vector>
using namespace std;
class Solution
{
private:
    int rotatedsortedarray(int low, int high, vector<int> &nums, int target)
    {
        if (low > high)
        {
            return -1;
        }
        int mid = (low + high) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        // left half sorted
        if (nums[low] <= nums[mid])
        {
            if (nums[low] <= target && target <= nums[mid])
            {
                return rotatedsortedarray(low, mid - 1, nums, target);
            }
            else
            {
                return rotatedsortedarray(mid + 1, high, nums, target);
            }
        }
        // right half sorted
        else
        {
            if (nums[mid] <= target && target <= nums[high])
            {
                return rotatedsortedarray(mid + 1, high, nums, target);
            }
            else
            {
                return rotatedsortedarray(low, mid - 1, nums, target);
            }
        }
    }

public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        return rotatedsortedarray(0, n - 1, nums, target);
    }
};