#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMedianUtil(const vector<int>& A, int startA, int endA, const vector<int>& B, int startB, int endB) {
        int lenA = endA - startA + 1;
        int lenB = endB - startB + 1;

        if (lenA > lenB) {
            return findMedianUtil(B, startB, endB, A, startA, endA);
        }

        if (lenA == 0) {
            if (lenB % 2 == 0) {
                return (B[startB + lenB / 2 - 1] + B[startB + lenB / 2]) / 2.0;
            } else {
                return B[startB + lenB / 2];
            }
        }

        if (lenA == 1 && lenB == 1) {
            return (A[startA] + B[startB]) / 2.0;
        }

        int idxA = (startA + endA) / 2;
        int idxB = (startB + endB) / 2;

        if ((lenA + lenB) % 2 == 0) {
            if (A[idxA] <= B[idxB]) {
                return findMedianUtil(A, idxA, endA, B, startB, endB - idxA + startA);
            } else {
                return findMedianUtil(A, startA, endA - idxA + startA, B, idxB, endB);
            }
        } else {
            if (A[idxA] <= B[idxB]) {
                return findMedianUtil(A, idxA, endA, B, startB, endB - idxA + startA);
            } else {
                return findMedianUtil(A, startA, endA - idxA + startA, B, idxB, endB);
            }
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int totalLen = nums1.size() + nums2.size();
        if (totalLen % 2 == 1) {
            return findMedianUtil(nums1, 0, nums1.size() - 1, nums2, 0, nums2.size() - 1);
        } else {
            return (findMedianUtil(nums1, 0, nums1.size() - 1, nums2, 0, nums2.size() - 1) + findMedianUtil(nums1, 0, nums1.size() - 1, nums2, 0, nums2.size() - 1)) / 2.0;
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << "Median of the arrays: " << sol.findMedianSortedArrays(nums1, nums2) << endl;

    vector<int> nums3 = {1, 2};
    vector<int> nums4 = {3, 4};
    cout << "Median of the arrays: " << sol.findMedianSortedArrays(nums3, nums4) << endl;

    return 0;
}
