class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        unordered_set<string> result;
        for (char ch = 'a'; ch <= 'z'; ch++) {
            int left = s.find(ch);
            int right = s.rfind(ch);
            if (left != string::npos && right != string::npos && left < right) {
                unordered_set<char> mids(s.begin() + left + 1, s.begin() + right);
                for (char mid : mids) {
                    string palindrome = {ch, mid, ch};
                    result.insert(palindrome);
                }
            }
        }
        return result.size();
    }
};