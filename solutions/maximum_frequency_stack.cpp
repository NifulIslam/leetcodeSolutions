/*https://leetcode.com/problems/maximum-frequency-stack/*/
class FreqStack {
public:
    priority_queue<vector<int> > pq;
    unordered_map<int,int> count;
    int pushNo;
    FreqStack() {
        pushNo=0;
    }
    
    void push(int val) {
        pq.push({++count[val], ++pushNo,val});
    }
    
    int pop() {
        int ans =pq.top()[2];
        count[ans]--;
        pq.pop();
        return ans;
    }
};
