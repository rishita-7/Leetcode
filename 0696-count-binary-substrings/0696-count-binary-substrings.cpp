class Solution {
public:
    int countBinarySubstrings(string s) {
        int prevRun = 0, currRun = 1, result = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i-1]) {
                currRun++;
            } else {
                result += min(prevRun, currRun);
                prevRun = currRun;
                currRun = 1;
            }
        }
        result += min(prevRun, currRun);
        return result;
    }
};
