#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

vector<int> findAngrams(string s,string p){
    vector<int> result;
    if(s.size()<p.size()){
        return result;
    }

    vector<int> pFreq(26,0);
    vector<int> sFreq(26,0);

    for(char c :p){
        pFreq[c-'a']++;
    }

    int windowSize = p.size();
    
    for(int i=0; i<windowSize; i++){
        sFreq[s[i] - 'a']++;
    }

    if(sFreq == pFreq){
        result.push_back(0);
    }

    for(int i = windowSize; i<s.size(); i++){
        sFreq[s[i] - 'a']++;
        sFreq[s[i-windowSize]-'a']--;

        if(sFreq == pFreq){
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
