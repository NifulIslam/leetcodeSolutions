/*https://leetcode.com/problems/house-robber/*/
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return robUtil(dp,nums,nums.size()-1);
        
    }
    int robUtil(vector<int> & dp, vector<int> & nums , int index){
        if(index<0){return 0;}
        if(dp[index]!=-1){return dp[index];}
        int take = nums[index]+ robUtil(dp,nums,index-2);
        int nottake = robUtil(dp,nums,index-1);
        return dp[index]=max(take,nottake);
    }
};
