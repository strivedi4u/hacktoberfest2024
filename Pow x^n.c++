class Solution{
public:
double myPow(double x, int n){
    if(x==0)return 0;
    if(x==1) return 1;
    if(n==0)return 1;

    long y=n;
    double ans= 1.0;
    if(y<0){
        x=1/x;
        y=-y;
    }
while(y>0){
if(y%2==0){
    ans *=x;
}
x*=x;
y=y/2;
}
return ans;
}}