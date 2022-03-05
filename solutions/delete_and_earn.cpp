/*https://leetcode.com/problems/delete-and-earn/*/
class Solution {
public:
    
    int deleteAndEarn(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        sort(nums.begin(), nums.end());
        return deleteUtil(dp,nums, nums.size()-1);
        
    }
    int deleteUtil(vector<int> & dp, vector<int> & nums, int index){
        if(index<0){return 0;}
        if(dp[index]!=-1){return dp[index];}
        int earn = 0;
        int i= index;
        while(i>-1 && nums[index]==nums[i]){
            earn +=nums[i];
            i--;
        }
        while(i>-1 && nums[index]==nums[i]+1){
            i--;
        }
        int take = earn+deleteUtil(dp,nums,i);
        int nottake= deleteUtil(dp,nums,index-1);
        return dp[index]=max(take,nottake);
        
        
    }
};
