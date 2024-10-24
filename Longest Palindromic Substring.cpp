#include <iostream>
#include <string>
#include <vector>
using namespace std;

string longestPalindrome(string s) {
    int n = s.length();
    
    if (n == 0) return "";  // Edge case: empty string
    
    // Table to store whether s[i...j] is a palindrome
    vector<vector<bool>> dp(n, vector<bool>(n, false));

    int maxLength = 1;  // The minimum palindrome length is 1 (single character)
    int start = 0;      // Start index of the longest palindromic substring

    // All substrings of length 1 are palindromes
    for (int i = 0; i < n; i++)
        dp[i][i] = true;

    // Check for substrings of length 2
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            start = i;
            maxLength = 2;
        }
    }

    // Check for substrings longer than 2
    for (int len = 3; len <= n; len++) {
        for (int i = 0; i < n - len + 1; i++) {
            int j = i + len - 1;  // Ending index of the current substring

            // If the current substring is a palindrome
            if (s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;

                if (len > maxLength) {
                    start = i;
                    maxLength = len;
                }
            }
        }
    }

    // Return the longest palindromic substring
    return s.substr(start, maxLength);
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    string result = longestPalindrome(s);
    cout << "The longest palindromic substring is: " << result << endl;

    return 0;
}
