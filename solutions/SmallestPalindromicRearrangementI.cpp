/*https://leetcode.com/problems/smallest-palindromic-rearrangement-i/description/*/
class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        int bucket[26] = {0};

        for (int i = 0; i < n; i++) {
            bucket[s[i] - 'a']++;
        }

        int left = 0;
        int right = n - 1;

        for (int i = 0; i < 26; i++) {
            if(bucket[i]!=0 && bucket[i]%2==1){
                s[n/2]= i + 'a';
                bucket[i]--;
            }
            while (bucket[i] > 0) {
                char c = i + 'a';
                s[left++] = c;
                s[right--] = c;
                bucket[i]= bucket[i]-2;
            }
        }

        return s;
        
    }
};
