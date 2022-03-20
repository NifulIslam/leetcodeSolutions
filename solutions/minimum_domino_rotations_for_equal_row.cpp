/*https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/*/
class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int result =INT_MAX;
        bool flag = false;
        for(int i=1; i< 7; i++){
            int changeNeed = minRotation(tops,bottoms,i);
            if(changeNeed!=-1){
                flag=1;
                result = min(result,changeNeed);
            }
        }
        return flag==1? result : -1;
        
    }
    int minRotation(vector<int>& tops, vector<int>& bottoms, int num){
        int n=tops.size();
        int bottomRotation=0;
        int topRotation=0;
        for(int i=0; i<n; i++){
            if(tops[i]!=num && bottoms[i]!=num) return -1;
            if(tops[i]==num && bottoms[i]!=num) bottomRotation++;
            if(tops[i]!=num && bottoms[i]==num) topRotation++;
        }
        return min(topRotation, bottomRotation);
    }
    
};
