// Problem statement
// You have been given a random integer array/list(ARR) of size N. You have been required to push all the zeros that are present in the array/list to the end of it. Also, make sure to maintain the relative order of the non-zero elements.

// Note:
// Change in the input array/list itself. You don't need to return or print the elements.

// You need to do this in one scan of array only. Don't use extra space.

// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 1 <= t <= 10^2
// 0 <= N <= 10^5
// Time Limit: 1 sec
// Sample Input 1:
// 1
// 7
// 2 0 0 1 3 0 0
// Sample Output 1:
// 2 1 3 0 0 0 0
//  Explanation for the Sample Input 1 :
// All the zeros have been pushed towards the end of the array/list. Another important fact is that the order of the non-zero elements have been maintained as they appear in the input array/list.
// Sample Input 2:
// 2
// 5
// 0 3 0 2 0
// 5
// 9 0 0 8 2
// Sample Output 2:
// 3 2 0 0 0
// 9 8 2 0 0

// C++

#include <bits/stdc++.h>
#include <vector>
using namespace std;

void push0ToEnd(vector<int>& nums) {
	if (nums.empty()) {
        throw invalid_argument("Vector cannot be empty.");
    }

    int nonZeroIndex = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i]!= 0) {
            nums[nonZeroIndex++] = nums[i];
        }
    }
    for (int i = nonZeroIndex; i < nums.size(); i++) {
        nums[i] = 0;
    }
}

int main()
{
	int t;
	cin >> t;
	while (t > 0)
	{
		int n;
		cin >> n;
		vector<int> nums;
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			nums.push_back(x);
		}
		push0ToEnd(nums);
		for (int i = 0; i < nums.size(); i++)
		{
			cout << nums[i] << " ";
		}
	}
	return 0;
}

// Java

// public class Solution {
//     public static void pushZerosAtEnd(int[] arr) {
//     	int i , j;
//         for(i=0 , j=0 ; j<arr.length;j++){
//             if(arr[j] != 0){
//                 arr[i] = arr[j];
//                 i++;
//             }
//         }
//         for(int k = i ; k<arr.length ; k++){
//             arr[k] = 0;
//         }
//     }
// }