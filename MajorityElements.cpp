#include <bits/stdc++.h>

int majorityElement(vector<int> v) {
    map<int,int> mpp;  // Create a map to store the frequency of each element

    for(int i = 0; i < v.size(); i++) {
        mpp[v[i]]++;  // Increment the count for the current element
    }

    for(auto it : mpp) {
        if (it.second > (v.size() / 2)) {  // Check if the count exceeds n/2
            return it.first;  // Return the majority element
        }
    }

    return -1;  // Return -1 if no majority element exists
}
