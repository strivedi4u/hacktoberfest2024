#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int longestSubstringWithoutRepeating(string s) {
    unordered_map<char, int> charIndexMap;  // To store the last index of every character
    int maxLength = 0;  // Length of the longest substring without repeating characters
    int start = 0;  // Start of current window

    for (int end = 0; end < s.length(); end++) {
        char currentChar = s[end];

        
        if (charIndexMap.find(currentChar) != charIndexMap.end() && charIndexMap[currentChar] >= start) {
            start = charIndexMap[currentChar] + 1;  // Move the start to the right of the repeating character
        }

        charIndexMap[currentChar] = end;  // Update the last index of the current character
        maxLength = max(maxLength, end - start + 1);  // Calculate the maximum length
    }

    return maxLength;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    int result = longestSubstringWithoutRepeating(input);
    cout << "The length of the longest substring without repeating characters is: " << result << endl;

    return 0;
}
