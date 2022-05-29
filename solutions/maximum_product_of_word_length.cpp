/*https://leetcode.com/problems/maximum-product-of-word-lengths/*/
class Solution {
public:
    int wordsMap[1010][26];
    int maxProduct(vector<string>& words) {
        memset(wordsMap,0,sizeof(wordsMap))      ; fillMap(words);
        int maxProduct=0;
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                bool flag =0;
                for(int k=0;k<26;k++){
                    if(wordsMap[i][k] && wordsMap[j][k]){
                        flag=1;break;
                    }
                }
                if(!flag)
                {    int a=words[i].size()*words[j].size();
                    maxProduct=max(maxProduct,a);
                }
            }
        }
        return maxProduct;
        
        
        
    }
    void fillMap(vector<string>& words){
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].size();j++){
                wordsMap[i][words[i][j]-'a']++;
            }
        }
    }
};
