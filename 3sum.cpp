class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
         sort(nums.begin(), nums.end());
        set<vector<int>> s;
         vector<vector<int>> output;
        for(int i=0;i<nums.size();i++)
        {
            int j=i+1,k=nums.size()-1;
            while(j<k)
            {
                if(nums[i]+nums[j]+nums[k]==0)
               {
                    s.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
                else if(nums[i]+nums[j]+nums[k]>0)
                k--;
                else
                j++;
            }
        }
        for(auto x:s)
        output.push_back(x);
        return output;
    }
};
