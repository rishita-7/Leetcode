class Solution {
public:
    int numSub(string s) {
        int m= 1e9+7;
        long result=0,count=0;
        for(char c:s){
            if(c=='1'){
                count++;
                result+=count;
                result%=m;
            }
            else
                count=0;
        }
        return (int)result;
    }
};