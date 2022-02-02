/*https://leetcode.com/problems/find-all-anagrams-in-a-string/*/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if(s.size()<p.size()){return ans;}
        vector<int> mask (27,0);
        vector<int> stringMask(27,0);
        fillMask(mask,p,p.size());
        fillMask(stringMask,s,p.size());
        int i=0, j=p.size();
        while(j!=s.size()){
            if(matchMask(mask, stringMask)){ans.push_back(i);}
            stringMask[s[i]-'a']--;
            stringMask[s[j]-'a']++;
            i++;j++;
            
        }
        if(matchMask(mask, stringMask)){ans.push_back(i);}
        return ans;
        
    }
    bool matchMask(vector<int> &mask1, vector<int> &mask2 ){
        for(int i=0; i< 27; i++){
            if(mask1[i]!=mask2[i]){return false;}
        }
        return true;
    }
    void fillMask(vector<int> &mask, string s, int end){
        for(int i=0; i< end; i++){
         mask[s[i]-'a']++;   
        }
    }
};
