
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void generateLexicographicalNumbers(int current, int n, vector<int>& result) {
        if (current > n) return;
        
        result.push_back(current);
        
        for (int i = 0; i <= 9; i++) {
            int next = current * 10 + i;
            if (next > n) break;
            generateLexicographicalNumbers(next, n, result);
        }
    }
    
    vector<int> getLexicographicalNumbers(int n) {
        vector<int> result;
        for (int i = 1; i <= 9; i++) {
            if (i > n) break;
            generateLexicographicalNumbers(i, n, result);
        }
        return result;
    }
};

int main() {
    Solution sol;
    int n = 13;
    vector<int> result = sol.getLexicographicalNumbers(n);
    
    for (int num : result) {
        cout << num << " ";
    }
    return 0;
}

// Time Complexity: O(n)
