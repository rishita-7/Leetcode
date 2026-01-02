class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> seen;
        for (int x : nums) {
            if (!seen.insert(x).second) return x; // first element that repeats
        }
        return -1; // should never hit for valid inputs
    }
};
