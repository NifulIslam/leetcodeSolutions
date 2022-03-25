/*https://leetcode.com/problems/two-city-scheduling/*/
bool diffComp(vector<int>& cost1 ,vector<int>& cost2 ){
    
    return abs(cost1[0]-cost1[1])>= abs(cost2[0]-cost2[1]);
}
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n=costs.size();
        int city1Need=(n>>1);
        int city2Need=(n>>1);
        int skipped=0;
        int cost=0;
        sort(costs.begin(),costs.end(),diffComp);
        for(int i=0; i<n; i++){
            if(costs[i][0]==costs[i][1]){
                skipped+=costs[i][1];
                continue;
            }
            if(costs[i][0]>costs[i][1] && city1Need!=0 ){
                city1Need--;
                cost+=costs[i][1];
                continue;
            }
            if(costs[i][0]<costs[i][1] && city2Need!=0 ){
                city2Need--;
                cost+=costs[i][0];
                continue;
            }
            if( city2Need!=0){
                city2Need--;
                cost+=costs[i][0];
                continue;
            }
             city1Need--;
                cost+=costs[i][1];
                continue;
        }
        return cost+skipped;
        
        
    }
};
