//     Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

//     An input string is valid if:

//     Open brackets must be closed by the same type of brackets.
//     Open brackets must be closed in the correct order.
//     Every close bracket has a corresponding open bracket of the same type.


#include<bits/stdc++.h>
using namespace std;

bool isValid(string s) {
        // approach  - using stack
        int n = s.size();
        stack<char> st;
        if(n == 1) return false;
        for(int i = 0 ; i<n ; i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                st.push(s[i]);
            }
            else if((s[i] == ')' && st.empty()) || (s[i] == ']' && st.empty()) || (s[i] == '}' && st.empty())) return false;
            
            else if((s[i] == ')' && st.top() != '(') || (s[i] == ']' && st.top() != '[') || (s[i] == '}' && st.top() != '{')) return false;

            else if((s[i] == ')' && st.top() == '(') || (s[i] == ']' && st.top() == '[') || (s[i] == '}' && st.top() == '{')){
                st.pop();
            }

        }

        if(st.empty()) return true;

        return false;
}
int main(){
    string s = "()()";
    cout<<isValid(s)<<endl;
    return 0;
}