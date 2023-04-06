/*
https://leetcode.com/problems/number-of-closed-islands/description/
*/
class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        vector<vector<int>> dp (n, vector<int>(m,-1));
        vector<vector<int>> moves={
            {-1,0},
            {1,0},
            {0,-1},
            {0,1},
        };
        int count =0;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m; j++){
                if(!grid[i][j] && dp[i][j]==-1){
                    count+=dfs(grid,dp,moves,i,j);
                }
            }
        }
        return count;
    }
    int dfs(vector<vector<int>>& grid, vector<vector<int>>& dp,  vector<vector<int>>& moves, int i, int j){
        if(i>=grid.size() || j>= grid[0].size()){
            return 0;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(grid[i][j]==1)
            return dp[i][j]=1;
        
        dp[i][j]=1;
        for(auto & move : moves){
            int a= dfs(grid,dp,moves,i+move[0],j+move[1]);
            dp[i][j]= dp[i][j] && a;
        }
        return dp[i][j];
    }
};
