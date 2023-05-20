/*
https://leetcode.com/problems/is-graph-bipartite/description/
*/

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> visited(n)   ;
        for(int i=0 ; i<n; i++){
            int ans= dfs(visited,graph, i, visited[i]);
            if(!ans)
                return 0;
        }
        return 1;
    }
    bool dfs(vector<int> & visited, vector<vector<int>>& graph , int i, int expect  ){
        if(visited[i]!=0 && visited[i]!=expect)
            return false;
        if(visited[i]!=0 && visited[i]==expect)
            return true;
        bool ans=1;
        
        if(expect==0){
            expect=-1;
        }
        else{
            expect*=-1;
        }
        visited[i]=-expect;

        for(int & j: graph[i]){
            ans= ans & (dfs(visited,graph,j,expect));
        }
        return ans;
    }
};
