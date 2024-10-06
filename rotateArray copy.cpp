// Problem statement
// You have been given a random integer array/list(ARR) of size N. Write a function that rotates the given array/list by D elements(towards the left).

//  Note:
// Change in the input array/list itself.You don't need to return or print the elements.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 1 <= t <= 10^4
// 0 <= N <= 10^6
// 0 <= D <= N
// Time Limit: 1 sec
// Sample Input 1:
// 1
// 7
// 1 2 3 4 5 6 7
// 2
// Sample Output 1:
// 3 4 5 6 7 1 2
// Sample Input 2:
// 2
// 7
// 1 2 3 4 5 6 7
// 0
// 4
// 1 2 3 4
// 2
// Sample Output 2:
// 1 2 3 4 5 6 7
// 3 4 1 2

// C++

#include <bits/stdc++.h>
using namespace std;

void rotate(int ar[], int n, int d)
{
	d = d % n;
	int temp[d];
	// Copy first d elements to a temp array
	for (int i = 0; i < n; i++)
	{
		temp[i] = ar[i];
	}
	// Move rest of the element to the front
	for (int j = 0; j < n - d; j++)
	{
		ar[j] = ar[j + d];
	}
	// Copy temp array to the end
	for (int k = 0; k < d; k++)
	{
		ar[n - d + k] = temp[k];
	}
}

int main()
{
	int t;
	cin >> t;
	while (t > 0)
	{
		t--;
		int n;
		cin >> n;
		int ar[n];
		for (int i = 0; i < n; i++)
		{
			cin >> ar[i];
		}
		int d;
		cin >> d;
		for (int i = 0; i < n; i++)
		{
			cout << ar[i] << " ";
		}
		cout << endl;
	}
	return 0;
}

// Java

// public class Solution {
//     public static void rotate(int[] arr, int d) {
//         int []arr1 = new int[arr.length];
//         int i;
//         for(i=0 ; i<arr.length ; i++){
//             arr1[i] = arr[i];
//         }
//         for(i=0 ; i< arr.length-d ; i++){
//             arr[i] = arr1[i+d];
//         }
//         for(int j = i ; j < arr.length ; j++){
//             arr[j] = arr1[d - arr.length + j];
//         }
//     }
// }