class Solution {
public:
    bool detectCapitalUse(string word) {
        int count=0;
        for(char c: word){
            count+=(isupper(c)?1:0);
        }
        if( count==word.size()||count==0||(count==1 && isupper(word[0])))
            return true;
        else return false;
    }
};