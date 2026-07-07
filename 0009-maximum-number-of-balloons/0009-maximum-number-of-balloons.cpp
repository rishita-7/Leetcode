class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>have;
        for(char c:text){
           have[c]++;
        }
        unordered_map<char,int>need;
        need['b']=1;
        need['a']=1;
        need['l']=2;
        need['o']=2;
        need['n']=1;
        int res=INT_MAX;
        for(auto c:need){
            res=min(res,have[c.first]/c.second);
        }
        return res;
    }
};