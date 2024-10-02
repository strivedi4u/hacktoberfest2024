#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
void solve(){
    string s;
    cin >> s;
    int p=0,n=s.size();
    int start=0,end=n-1;
    while(start<end){
        if(s[start]!=s[end]) {
            p=1;
            break;
        }
        start++,end--;
    }
    if(p==0) cout<<"true"<<endl;
    if(p==1) cout<<"false"<<endl;
}

int main() 
{
 solve();
return 0;
}