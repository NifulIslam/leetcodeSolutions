/*https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/*/
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        vector<int> forwardPrefix(n);
        vector<int> backwardPrefix(n);
        forwardPrefix[0]=cardPoints[0];
        backwardPrefix[n-1]=cardPoints[n-1];
        for(int i=1 ;i<n;i++){
            forwardPrefix[i]=forwardPrefix[i-1]+cardPoints[i];
        }
        for(int i=n-2; i>-1;i--){
            backwardPrefix[i]=backwardPrefix[i+1]+cardPoints[i];
        }
        int maxSum=-1;
        for(int i=0; i<=k; i++){
            int backTake=n-k+i;
            if(i==0){
                maxSum=max(maxSum,backwardPrefix[backTake]);
                continue;
            }
            if(i==k){
                maxSum=max(maxSum,forwardPrefix[i-1]);
                continue;
            }
            int a=backwardPrefix[backTake]+forwardPrefix[i-1];
            maxSum=max(maxSum,a);
            
        }
        return maxSum;
    }
};
