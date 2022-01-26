/*https://leetcode.com/problems/target-sum/*/
class Solution {
public:
    int actualTarget;
    int findTargetSumWays(vector<int>& nums, int target) {
        actualTarget = target*2;
        target= abs(target);
        vector<vector<int>> dp (nums.size() ,vector<int>(target*2+1,-1));
        return getWays(0,nums,target,dp);
        
        
    }
    int getWays(int index , vector<int> & nums, int target, vector<vector<int>>& dp){
        if(index==nums.size()){
            if(target==0){return 1;}
            return 0;
        }
        if(target>=0 && target<= actualTarget){
        if(dp[index][target]!=-1){return dp[index][target];}}
        int posPosib = getWays(index+1,nums,target-nums[index],dp );
        int negPosib = getWays(index+1, nums, target+nums[index],dp);
        int ans= posPosib+negPosib;
        if(target>=0&& target<= actualTarget){
        return dp[index][target]=ans ;}
        return ans;
    }
};
