/*
https://leetcode.com/problems/ipo/description/
*/
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();
        vector<pair<int,int>> afford(n);
        for(int i=0 ; i<n; i++){
            afford[i]={capital[i], profits[i]};
        }
        sort(afford.begin(), afford.end());
        priority_queue<int> prof;
        int i=0;
        while(k--){
            while(i<n && w>=afford[i].first){
                prof.push(afford[i].second);
                i++;
            }
            if(prof.empty())
                return w;
            w+=prof.top();
            prof.pop();
        }
        return w;   
    }
};
