// C++ Program to find the maximum subarray sum using nested loops 

#include <bits/stdc++.h>
using namespace std;

// Function to find the sum of subarray with maximum sum
int maxSubarraySum(vector<int> &arr) {
    int res = arr[0];
  
    // Outer loop for starting point of subarray
      for(int i = 0; i < arr.size(); i++) {
        int currSum = 0;
      
        // Inner loop for ending point of subarray
        for(int j = i; j < arr.size(); j++) {
            currSum = currSum + arr[j];
          
            // Update res if currSum is greater than res
            res = max(res, currSum);
        }
    }
    return res;
}

int main() {
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    cout<<"Enter Array: ";
    vector<int> arr;
    int t;
    for(int i=0; i<n; i++)
    {
        cin>>t;
        arr.push_back(t);
    }
    cout<<endl;
    cout <<"Maximum Subarray sum = "<< maxSubarraySum(arr)<<endl;
    return 0;
}
