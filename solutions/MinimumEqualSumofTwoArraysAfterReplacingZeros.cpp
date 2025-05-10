
/*https://leetcode.com/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros*/
class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0;
        long long sum2 = 0;
        long long zeros1 = 0, zeros2=0;
        for(int i=0; i<nums1.size(); i++){
            sum1 = sum1+ nums1[i];
            if(!nums1[i])
            {zeros1++;}
        }
        for(int i=0; i<nums2.size(); i++){
            sum2 = sum2+ nums2[i];
            if(!nums2[i])
            {zeros2++;}
        }
        if(sum1!=sum2 && (zeros1==0 || zeros2==0) && ((sum1<sum2 && (zeros1>(sum2-sum1) || zeros1==0 ) ) || (sum2<sum1 && ( (zeros2>(sum1-sum2))||zeros2==0 )))){return -1;}
        if(sum1==sum2 && ((zeros1!=0 || zeros2!=0) && !(zeros1!=0 && zeros2!=0))){return -1;}
        return max(sum1+zeros1, sum2+zeros2);
    }

};
