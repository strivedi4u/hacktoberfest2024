class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool> alpha(26, false); // Use 26 for all lowercase letters
        for (int i = 0; i < sentence.size(); i++) {
            alpha[sentence[i] - 'a'] = true; // Update the alpha vector
        }
        for (int i = 0; i < 26; i++) {
            if (!alpha[i])
                return false; // If any letter is missing, return false
        }
        return true; // All letters are present
    }
};
