/*https://leetcode.com/problems/stone-game-iv/*/
class Solution {
public:
    bool winnerSquareGame(int n1) {
        int n=1e5+10;
        vector<int> dp(n,-1);
        dp[0]=0;
        vector<int> squares;
        for(int i=1; i*i<n;i++){
            dp[i*i]=1;
            squares.push_back(i*i);
        }
        return isPossible(squares,dp,n1);
        
    }
    bool isPossible(vector<int> & squares, vector<int> & dp, int n){
        if(n<0){
            return 1;
        }
        if(dp[n]!=-1){return dp[n];}
        
        for(int & i : squares ){
            bool goI=isPossible(squares,dp,n-i);
            if(!goI){
                return dp[n]=1;
            }
        }
        
        return dp[n]=0;
        
    }
};
