class Solution {
public:
    bool checkString(string s) {
        int count_b=0;
        for(char c:s){
            if(c=='b')
                count_b=1;
            if(count_b!=0 && c=='a')
                return false;
        }
        return true;
    }
};