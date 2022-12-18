/*
https://leetcode.com/problems/daily-temperatures/description/
*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> ans(temperatures.size());
        for(int i=0 ; i< temperatures.size(); i++){
            if(st.empty()){ st.push(i);  continue ; }

            if(temperatures[i] > temperatures[st.top()]){
                
                while(!st.empty() &&  temperatures[i] > temperatures[st.top()] ){
                    ans[st.top()]=i -st.top() ; 
                    st.pop();
                }
                
            }
            st.push(i);
        }
        while(!st.empty()){
            ans[st.top()]=0;
            st.pop();
        }
        return ans;

    }
};
