/**
 * Enum representing the possible outcomes of a pattern matching operation.
 * TRUE if the pattern successfully matches the text, FALSE otherwise.
 */
enum Result {
    TRUE, FALSE
}

/**
 * The Solution class provides a method to determine if a given text matches a pattern.
 * The pattern supports the following special characters:
 * - '.' which matches any single character.
 * - '*' which matches zero or more occurrences of the preceding character.
 */
class Solution {
    // 2D array for memoization to store previously computed results for (text, pattern) indices.
    Result[][] memo;

    /**
     * Initializes the memoization table and initiates the pattern matching operation.
     *
     * @param text The string to be matched.
     * @param pattern The pattern containing regular expression symbols '.' and '*'.
     * @return true if the text matches the pattern, false otherwise.
     */
    public boolean isMatch(String text, String pattern) {
        // Allocate memoization table based on lengths of text and pattern.
        memo = new Result[text.length() + 1][pattern.length() + 1];
        // Begin recursive matching from the start of both text and pattern.
        return dp(0, 0, text, pattern);
    }

    /**
     * Helper method to recursively check if text starting from index `i` matches the pattern
     * starting from index `j`. This method utilizes memoization to improve efficiency.
     *
     * @param i The current index in the text string.
     * @param j The current index in the pattern string.
     * @param text The string to be matched.
     * @param pattern The pattern string.
     * @return true if text[i:] matches pattern[j:], false otherwise.
     */
    public boolean dp(int i, int j, String text, String pattern) {
        // Check if the result for the current indices has already been computed.
        if (memo[i][j] != null) {
            return memo[i][j] == Result.TRUE;
        }

        boolean ans;

        // Base case: if we are at the end of the pattern.
        if (j == pattern.length()) {
            // Match is successful only if we are also at the end of the text.
            ans = i == text.length();
        } else {
            // Check if the current characters in text and pattern match.
            boolean first_match = (i < text.length() &&
                                   (pattern.charAt(j) == text.charAt(i) ||
                                    pattern.charAt(j) == '.'));

            // Handle '*' in the pattern, which matches zero or more occurrences of the preceding element.
            if (j + 1 < pattern.length() && pattern.charAt(j + 1) == '*') {
                // Match zero of the preceding character (skip '*' and preceding character in pattern)
                // OR match one or more (proceed with text and continue with '*' in pattern).
                ans = (dp(i, j + 2, text, pattern) ||
                       (first_match && dp(i + 1, j, text, pattern)));
            } else {
                // No '*', so proceed with the next characters in both text and pattern if there's a match.
                ans = first_match && dp(i + 1, j + 1, text, pattern);
            }
        }

        // Memoize the result for the current indices and return the result.
        memo[i][j] = ans ? Result.TRUE : Result.FALSE;
        return ans;
    }
}