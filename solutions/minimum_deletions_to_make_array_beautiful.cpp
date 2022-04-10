/*https://leetcode.com/problems/minimum-deletions-to-make-array-beautiful/*/
class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int n=nums.size();
        int operations=0;
        for(int i=0; i<n-1; i++){
            if(!((i-operations)&1) && nums[i]==nums[i+1] ){
                operations++;
            }
            
        }
        if((n-operations)&1){
            operations++;
        }
        return operations;
        
    }
};
