/*
https://leetcode.com/problems/validate-stack-sequences/description/
*/
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int i=0,j=0, m=pushed.size(), n=popped.size();
        while(i<m && j<n){
            if(st.empty()){
                st.push(pushed[i]);
                i++;
                continue;
            }
            if(st.top()==popped[j]){
                j++;
                st.pop();
                continue;
            }
            st.push(pushed[i]);
            i++;
        }
        while(j<n && !st.empty() && st.top()==popped[j]){
             j++;
            st.pop();
        }
        return st.empty();
    }
};
