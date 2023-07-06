/*
https://leetcode.com/problems/longest-palindromic-substring/description/
*/
class Solution {
public:
    int check(string & s , int i ){
        //even
        int l=i,r=i, ans=0;
        while(l>=0 && r <s.size() && s[l]==s[r]){
            l--;r++;
        }
        int a= r-l-1;
        ans=max(ans,a);
        l=i,r=i-1;
        //odd
        while(l>=0 && r <s.size() && s[l]==s[r]){
            l--;r++;
        }
        a= r-l-1;
        ans=max(ans,a);
        return ans;
    }
    string longestPalindrome(string s) {
        int ans =1, start=0;
        for(int i=0; i<s.size(); i++){
            int ans_=check(s,i);
            if(ans_>ans){
                ans=ans_;
                
                    start=i-(ans/2);
                
            }
        }
        return s.substr(start,ans);
    }
};
