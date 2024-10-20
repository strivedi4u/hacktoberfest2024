class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0, j=n-1;
        int ht, wd,ans;
        int maxAns=0;
        while(i<j){
            ht= min(height[i], height[j]);
            wd=j-i;
            ans=ht*wd;
             maxAns= max(maxAns, ans);
           if(height[i]<height[j]){ 
            i++;
           }else{
            j--;
           } 
        }
        return maxAns;
    }
};