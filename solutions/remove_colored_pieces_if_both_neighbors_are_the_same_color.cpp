/*
https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/description/
*/
class Solution {
public:
    bool winnerOfGame(string colors) {
        int n= colors.size();
        int i=0, ca=0, cb=0;
        while(i<n){
            if(colors[i]=='A'){
                int ct=0;
                while(i<n && colors[i]=='A'){
                    ct++;
                    i++;
                }
                ct=max(0,ct-2);
                ca+=ct;
                
            }
            else{
                int ct=0;
                while(i<n && colors[i]=='B'){
                    ct++;
                    i++;
                }
                ct=max(0,ct-2);
                cb+=ct;
              
            }
            
        }
        return ca>cb;
    }
};
