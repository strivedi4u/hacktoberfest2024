// C++ Program to find the maximum subarray sum using nested loops 

#include <bits/stdc++.h>
using namespace std;

// Function to find the sum of subarray with maximum sum using kadanes Algorithm
int maxSubarraySum(vector<int> &arr) {
    int res = arr[0];
    int currSum = 0;
    //Here we will iterate the given array with a single loop 
      for(int i = 0; i < arr.size(); i++) {
       
        currSum+=arr[i];
        
        if(currSum>res){
            res=currSum;
        }
  // If at any point the currSum becomes less than 0, we will set the currSum as 0     
        if(currSum<0){
            currSum=0;
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
