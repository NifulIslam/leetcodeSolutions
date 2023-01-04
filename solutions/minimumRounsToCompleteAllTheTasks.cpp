/*
https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/description/
*/
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        vector<int> isPossible(1e5+10,0);
        isPossible[2]=isPossible[3]=1;
        for(int i=2; i<isPossible.size(); i++){
            if(isPossible[i]){
                if(i+2<isPossible.size()){
                    if(!isPossible[i+2]){
                        isPossible[i+2]=isPossible[i]+1;
                    }
                    else{
                        isPossible[i+2]=min(isPossible[i+2],isPossible[i]+1 );
                    }
                }
                if(i+3<isPossible.size()){
                    if(!isPossible[i+3]){
                        isPossible[i+3]=isPossible[i]+1;
                    }
                    else{
                        isPossible[i+3]=min(isPossible[i+3],isPossible[i]+1 );
                    }
                }

            }
        }
        
        int rounds=0;
        unordered_map<int,int> count;
        for(int & i: tasks){
            count[i]++;
        }
        
        for (auto & i : count){
            if(!isPossible[i.second])
                return -1;
            rounds+= isPossible[i.second];
            
        }
        return rounds;
    }
};
