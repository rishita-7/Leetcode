class Solution {
public:
    int strStr(string haystack, string needle) {
        int hs=haystack.size();
        int n=needle.size();
        if (n>hs)
            return -1;
        for(int i=0;i<=hs-n;i++){
            if(haystack.substr(i,n)==needle)
                return i;
        }
        return -1;
    }
};