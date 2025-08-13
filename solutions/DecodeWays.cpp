/*https://leetcode.com/problems/decode-ways/description/?envType=problem-list-v2&envId=dynamic-programming*/

class Solution {
public:
    int numDecodings(string s) {
        if(s[0]=='0') return 0;
        vector <int> dp(s.size(),-1);
        return solve(s,0,dp);
    }
    int solve(string& s, int i, vector <int>& dp){
        if(i==s.size()){return 1;}
        if(i>s.size()){return 0;}
        if(dp[i]!=-1) {return dp[i];}
        if(s[i]=='0'){
            dp[i]=0;
            return 0;
        }
        int take =0, not_take=0;
        not_take = solve(s,i+1, dp);
        if( i<s.size()-1 && 
        (s[i]=='1' ||
        ( s[i]=='2' && (s[i+1]>='0' && s[i+1]<='6' )
        )
        ) ){
            take = solve(s, i+2, dp);
        }

        dp[i] = take+not_take;
        return dp[i];
    }

};
