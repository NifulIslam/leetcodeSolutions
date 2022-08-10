/*
https://leetcode.com/problems/longest-ideal-subsequence/
*/
class Solution {
public:
    unordered_map<char,int> maxGain;
    int longestIdealString(string s, int k) {
        maxGain[s[s.size()-1]] = 1;
        int ans=1;
        for(int i =s.size()-2; i>=0; i-- ){
            maxGain[s[i]] = 1+gain(s[i],k);
            ans=max(ans,maxGain[s[i]]);
            
        }
        return ans;
    }
    int gain(char c , int k){
        int maxMatch=0;
        for(int i=0 ; i<=k ; i++){   
            maxMatch= max(maxMatch, maxGain[c+i]);
            maxMatch= max(maxMatch, maxGain[c-i]);
            
        }
        return maxMatch;
    }
};
