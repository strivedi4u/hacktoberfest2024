#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

vector<int> findAngrams(string s,string p){
    vector<int> result;
    if(s.size()<p.size()){
        return result; // If the target string is smaller than the pattern, no anagrams possible
    }

    // Create frequency maps for the pattern and the sliding window
    vector<int> pFreq(26,0);    // Frequency of each character in pattern
    vector<int> sFreq(26,0);    // Frequency of each character in current sliding window

    // Populate the frequency map for the pattern
    for(char c :p){
        pFreq[c-'a']++;
    }

    // Sliding window over the string 's'
    int windowSize = p.size();
    
    // Process the first window of size equal to the length of 'p'
    for(int i=0; i<windowSize; i++){
        sFreq[s[i] - 'a']++;
    }

    // If the first window matches, add the starting index to the result
    if(sFreq == pFreq){
        result.push_back(0);
    }

    // Now slide the window over the string 's'
    for(int i = windowSize; i<s.size(); i++){
        sFreq[s[i] - 'a']++;                      // Add new character to the window
        sFreq[s[i-windowSize]-'a']--;             // Remove the old character (outside the window)

        if(sFreq == pFreq){                       // If after sliding, the window matches the pattern, add the starting index
            result.push_back(i - windowSize + 1);
        }
    }
    return result;
}

int main(){
    string s = "cbaebabacd";
    string p = "abc";

    vector<int> anagramIndices = findAngrams(s,p);

    cout << "Anagram Indices: ";
    for(int index : anagramIndices){
        cout<<index<<" ";
    }
    cout << endl;

    return 0;
}
