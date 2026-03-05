class Solution {
public:
    int minOperations(string s) {
        char set_bit='0';
        int min1=0,min2=0;
        for(char c:s){
            if(c!=set_bit){
                min1++;
            }
            set_bit=set_bit=='0'?'1':'0';
        }
        set_bit='1';
        for(char c:s){
            if(c!=set_bit){
                min2++;
            }
            set_bit=set_bit=='0'?'1':'0';
        }
        return min(min1,min2);
    }
};