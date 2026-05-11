class Solution {
public:
    int alternateDigitSum(int n) {
        int f=1;
        int sum=0;
        string s=to_string(n);
        for(char c:s){
            if(f){
                sum+=(c-'0');
                f=0;
            }
            else{
                sum-=(c-'0');
                f=1;
            }
        }
        return sum;
    }
};