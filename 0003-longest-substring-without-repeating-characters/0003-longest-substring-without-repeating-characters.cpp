class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       unordered_map<char,int>lastOccurence;
       int left=0,max_len=0;
       for(int right=0;right<s.size();right++){
            char c=s[right];
            if(lastOccurence.count(c) && lastOccurence[c]>=left){
                left=lastOccurence[c]+1;
            }
            lastOccurence[c]=right;
            max_len=max(max_len,right-left+1);
       }
       return max_len;
    }
};