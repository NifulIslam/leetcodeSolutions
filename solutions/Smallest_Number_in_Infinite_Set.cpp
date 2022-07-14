/*
https://leetcode.com/problems/smallest-number-in-infinite-set/
*/
class SmallestInfiniteSet {
public:
    int current;
     priority_queue<int, vector<int>, greater<int> > pq;
    unordered_set<int> all;
    SmallestInfiniteSet() {
        current=1;
    }
    
    int popSmallest() {
        if(pq.empty() ||pq.top()>current){
            current++;
            return current-1;
        }
        int val= pq.top(); pq.pop();all.erase(val);
        if(val==current)
            current++;
        return val;
        
    }
    
    void addBack(int num) {
        if(all.find(num)==all.end()){
            all.insert(num);
            pq.push(num);
        }
        
    }
};

