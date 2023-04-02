/*https://leetcode.com/problems/successful-pairs-of-spells-and-potions/submissions/926647933/*/
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        int n= spells.size();
        int m= potions.size();
        int mid,hi,lo;
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            hi=m-1,lo=0;
            while(lo<=hi){
                mid= lo+ (hi-lo)/2;
                if(1ll*potions[mid]*spells[i] >=success){
                    hi=mid-1;
                    continue;
                }
                lo=mid+1;

            }
            ans[i]=m-lo;

        }
        return ans;
    }
};
