#include <bits/stdc++.h>


using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    map<char, int> a;
    for(int i = 0; i < s.size(); i++ ){
        a[s[i]]++;
    }
    int f = 0;
    char ch;
    for(int i = 0; i < s.size(); i++ ){
        if ( a[s[i]]  == 1){
            ch = s[i];
            f++;
            break;
        }
    }
    if( f == 0){
        cout << "-1" << endl;
    } else {
        cout << ch << endl;
    }
}