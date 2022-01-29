/*https://leetcode.com/problems/largest-rectangle-in-histogram/*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nextSmaller(heights.size(),heights.size());
        vector<int> nextGreater=findPreviousSmaller(heights);
        stack<int> st;stack<int> st2;
        for(int i=0; i< heights.size(); i++){
            if(st.empty()|| heights[st.top()]<=heights[i]){
                st.push(i);
                continue;
            }
            while(!st.empty() && heights[st.top()]>heights[i]){
                nextSmaller[st.top()]=i;
                st.pop();
            } 
            st.push(i);
        }
       int largestRact= INT_MIN;
        for(int i=0; i< heights.size(); i++){
            int ract =(heights[i]*(nextSmaller[i]-i))+(heights[i]*(i-nextGreater[i])) - heights[i];
            largestRact= max(largestRact, ract);
        }
        return largestRact;
        
    }
    vector<int> findPreviousSmaller(vector<int> & arr){
        int n= arr.size();
         stack<int> s;
        vector<int> ans;
 
    for (int i = 0; i < n; i++)
    {
       
        while (!s.empty())
        {
            if (arr[s.top()] < arr[i])
            {
               ans.push_back(s.top());
                break;
            }
            else {
                s.pop();
            }
        }
 
        if (s.empty()) {
           ans.push_back(-1);
        }
 
        s.push(i);
    }
        return ans;
    }
};
