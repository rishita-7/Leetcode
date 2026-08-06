class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       set<char> letter;
       int n=s.size();
       int left=0,right=0;
       int maxlen=0;
       while(right<n){
            char c=s[right];
            while(letter.count(c)){
                letter.erase(s[left]);
                left++;
            }
            letter.insert(c);
            maxlen=max(maxlen,right-left+1);
            right++;
       }
       return maxlen;
    }
};