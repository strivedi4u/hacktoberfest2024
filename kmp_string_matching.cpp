#include <iostream>
#include <string>
using namespace std;

// Function to perform the naive string matching algorithm
void stringMatching(string text, string pattern) {
    int textLength = text.length();
    int patternLength = pattern.length();

    // Loop through the text to check for the pattern at each position
    for (int i = 0; i <= textLength - patternLength; i++) {
        int j;
        
        // For the current position in text, check if the pattern matches
        for (j = 0; j < patternLength; j++) {
            if (text[i + j] != pattern[j]) {
                break; // Mismatch, break out of inner loop
            }
        }

        // If we found a match, the inner loop will have completed
        if (j == patternLength) {
            cout << "Pattern found at index " << i << endl;
        }
    }
}

int main() {
    string text, pattern;

    // Take input from the user
    cout << "Enter the text: ";
    getline(cin, text);

    cout << "Enter the pattern to search: ";
    getline(cin, pattern);

    // Perform string matching
    stringMatching(text, pattern);

    return 0;
}