/*
https://leetcode.com/problems/zigzag-conversion/description/
*/
class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> rows(numRows,"");
        bool flag=0;
        int i=0, n=s.size();
        while(i<n){
            if(!flag){
                int j=0;
                while(i<n && j<numRows){
                    rows[j++]+=s[i++];
                }
                flag=1;
                continue;
            }
            int j=numRows-2;
            while(i<n && j>0){
                rows[j--]+=s[i++];
            }
            flag=0;
        }
        string ans="";
        for(string & k: rows)
            ans+=k;
        return ans;
    }
};
