class Solution {
public:
    int maxOperations(string s) {
        int counted_ones = 0, ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                counted_ones++;
            } else if (i == 0 || s[i-1] == '1') {
                ans += counted_ones;
            }
        }
        return ans;
    }
};