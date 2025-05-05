/*https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/?envType=problem-list-v2&envId=binary-search*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(nums[0]<nums[n-1] || n==1){
            return nums[0];
        }
        int left =0, right = n-1,mid=0;
        while(left<right){
            mid = (left+right)/2;
            if(nums[mid]>nums[mid+1]){
                return nums[mid+1];
            }
            if(nums[0]<nums[mid]){
                left = mid+1;
            }
            else{
                right = mid;
            }
        }
        return nums[left];

    }
};
