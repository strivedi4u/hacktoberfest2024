/* KOSARAJU ALGORITHM
Intuition-
The goal is to find substrings that do not overlap, while ensuring that all occurrences of each character are included in their respective substring.

For example, consider the string "abcdade".

The substring "abcda" is invalid because not all occurrences of the character d are included.
The substring "abcdad" is valid, but if we choose this, the result will be two substrings: "abcdad" and "e". This gives us two substrings.
However, if we take "b", "c", and "e" as separate substrings, all of these are valid. This approach results in three substrings, which is the correct answer for this case.

Approach -
In the first loop, I record the starting and ending positions of each character. Specifically:

The start is the leftmost occurrence of the character.
The end is the rightmost occurrence of the character.
The detailed explanation is provided in the comments within the code.*/

#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> start(26, -1);
        vector<int> end(26, 0);
        vector<int> invalid(26, 0);
        vector<string> result;
        
        for (int i = 0; i < s.size(); i++) {
            int idx = s[i] - 'a';
            if (start[idx] == -1) start[idx] = i;
            end[idx] = i;
        }
       
        for (int i = 0; i < 26; i++) {
            if (start[i] == -1) continue;
            for (int k = start[i]; k <= end[i]; k++) {
                if (start[s[k] - 'a'] < start[i]) {
                    invalid[i] = 1;
                    break;
                } else end[i] = max(end[i], end[s[k] - 'a']);
            }
        }

        int lastCut = INT_MAX;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (i == start[s[i] - 'a'] && end[s[i] - 'a'] < lastCut && !invalid[s[i] - 'a']) {
                result.push_back(s.substr(i, end[s[i] - 'a'] - i + 1));
                lastCut = i;
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    string input = "abcdade";
    
    vector<string> result = sol.maxNumOfSubstrings(input);
    
    cout << "Maximum number of substrings: " << result.size() << endl;
    for (const string& substr : result) {
        cout << substr << endl;
    }

    return 0;
}
