/*
https://leetcode.com/problems/gas-station/description/
*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        long long int summ=0;
        for(int i=0 ; i< n ; i++)
            summ+=gas[i]-cost[i];       
        if(summ<0){return -1;}
        int maxNegative=1,curNegative=0;
        for(int i=0 ; i<2*n ; i++){
            int j=i%n;
            if(gas[j]-cost[j]<0){
                curNegative+=gas[j]-cost[j];
                maxNegative=min(maxNegative, curNegative);
                continue;
            }
            curNegative=0;
        }
        int cummulative=0, q_start=-1;
        for(int i=0 ; i<2*n ; i++){
            int j=i%n;
            if(cummulative>=0){
                cummulative+=gas[j]-cost[j];
                int j_=max(0,cummulative);
                if(j_>= -1*maxNegative){return (q_start+1)%n;}             
            }
            if(cummulative<0){
                cummulative=0;
                q_start=j;
            }
        }
        return -2;
    }
};
