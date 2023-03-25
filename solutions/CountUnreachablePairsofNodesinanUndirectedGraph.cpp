/*
https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/
*/
class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& connections) {
        unordered_map<int,vector<int>>  graph;
        for(int i=0; i<connections.size(); i++){
            graph[connections[i][0]].push_back(connections[i][1]);
            graph[connections[i][1]].push_back(connections[i][0]);
        }
        vector<bool>visited(n,0);
        vector<int> temp;
        for(int i=0; i<n; i++){
            if(visited[i])continue;
            int ct=0;
            dfs(graph,visited,i,ct);
            if(!ct)
                continue;
            temp.push_back(ct);
        }

        int total = 0;
        long long res=0;
        for(int i = 0;i<temp.size();i++){
            res+=(long)((long)temp[i]*(long)(n-total-temp[i]));
            total+=temp[i];
        }
        return res;
        

    }
        void dfs(unordered_map<int,vector<int>> & graph,vector<bool> & visited, int i, int & ct){
        if(visited[i])
            return;
        ct++;
        visited[i]=1;
        for(int & node : graph[i]){
            dfs(graph,visited,node,ct);
        }

    }
};
