class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>freq;
        for(char c:s){
            freq[c]++;
        }
        bool odd=false;
        int res=0;
        for(auto c:freq){
            int val=c.second;
            if(val%2==0) res+=val;
            else odd=true;
        }
        if(odd==false)  return res;
        for(auto c:freq){
            int val=c.second;
            if(val%2==1)
                res+=(val-1);
        }
        return res+1;
    }
};