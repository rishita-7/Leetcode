class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int needed = 1 << k; // 2^k possible codes
        unordered_set<string> seen;
        
        for (int i = 0; i <= (int)s.size() - k; i++) {
            string sub = s.substr(i, k);
            seen.insert(sub);
            if ((int)seen.size() == needed) return true;
        }
        
        return false;
    }
};
