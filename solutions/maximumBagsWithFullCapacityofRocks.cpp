/*
https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/description/
*/
class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n= capacity.size();
        vector<int> free_(n);
        for(int i=0 ; i<n ; i++){
            free_[i]= capacity[i]- rocks[i];
        }
        sort(free_.begin(), free_.end());
        int have=0;
        for(int i=0 ; i<n; i++){
            if(free_[i]==0){
                have++;
                continue;
            }
            if(additionalRocks<free_[i]){break;}
            additionalRocks-= free_[i];
            have++;

        }
        return have;
    }
};
