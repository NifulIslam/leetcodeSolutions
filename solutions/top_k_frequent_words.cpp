/* https://leetcode.com/problems/top-k-frequent-words/
*/
struct CustomCompare
{
    bool operator()(pair<int,string> & p1, pair<int,string> & p2)
    {
        if(p1.first!=p2.first){
            return p1.first<=p2.first;
        }
        return p1.second>=p2.second;
        
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pair<int,string>,vector<pair<int,string>>, CustomCompare > pq;
        unordered_map<string, int > count;
        for(string & i: words){
            count[i]++;
            pq.push({count[i],i});
        }
        vector<string> ans;
        unordered_set<string> ansSet;
        while(k--){
            string s=pq.top().second;
            pq.pop();
            if(ansSet.find(s)!=ansSet.end()){k++;continue;}
            ans.push_back(s);
            
            ansSet.insert(s);
        }
        return ans;
        
    }
};
