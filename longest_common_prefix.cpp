// # Longest Common Prefix in C++

// ## Description
// This program finds the longest common prefix among a vector of strings. The longest common prefix is the longest string that is a prefix of all the input strings.

// ## Approach
// 1. **Input:** A vector of strings.
// 2. **Initialization:** The first string is assumed to be the prefix.
// 3. **Comparison:** For each subsequent string, the prefix is reduced until it matches the beginning of the current string.
// 4. **Result:** The final prefix is returned, which will be the longest common prefix for all strings.

// ime Complexity
// - O(S), where S is the sum of all characters in the input strings


#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";

    string prefix = strs[0];

    for (int i = 1; i < strs.size(); i++) {
        while (strs[i].find(prefix) != 0) {
            prefix = prefix.substr(0, prefix.size() - 1);
            if (prefix.empty()) return "";
        }
    }

    return prefix;
}

int main() {
    vector<string> strs = {"flower", "flow", "flight"};
    string result = longestCommonPrefix(strs);
    
    if (!result.empty()) {
        cout << "Longest Common Prefix: " << result << endl;
    } else {
        cout << "There is no common prefix." << endl;
    }

    return 0;
}
