/*
https://leetcode.com/problems/minimum-size-subarray-sum/description/?envType=study-plan-v2&id=top-interview-150
*/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        vector<long int> prefixSum(n);
        long int summ=0;
        for(int i=0 ; i<n; i++){
            summ+=nums[i];
            prefixSum[i]=summ;
        }
        if(summ<target)
            return 0;
        int min_length=INT_MAX;
        for(int i=n-1; i>-1; i--){
            if(prefixSum[i]<target)
                break;
            long int find=prefixSum[i]-target;
            int index= upper_bound(prefixSum.begin(),prefixSum.end(),find)- prefixSum.begin();
            int ans= i-index+1;
            min_length= min(min_length,ans);
        }
        return min_length;
        
    }
};
