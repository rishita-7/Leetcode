class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       unordered_map<char,int>freq;
       if(s.size()==0) return 0;
       int l=0,r=0,maxlen=INT_MIN;
       while(r<s.size()){
        freq[s[r]]++;
        while(freq[s[r]]>1){
            freq[s[l]]--;
            l++;
        }
        maxlen=max(maxlen,r-l+1);
        r++;
       }
       return maxlen;
    }
};