class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>have; //available in magazine
        unordered_map<char,int>need; //needed in ransomNote
        for(char c:ransomNote)
            need[c]++;
        for(char c:magazine)
            have[c]++;
        for(auto a:need){
            if (a.second>have[a.first])
                return false;
        }
        return true;
    }
};