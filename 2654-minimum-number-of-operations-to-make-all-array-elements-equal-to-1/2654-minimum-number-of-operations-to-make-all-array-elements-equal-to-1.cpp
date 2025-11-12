class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        
        // If there's already a 1, just spread it
        int ones = count(nums.begin(), nums.end(), 1);
        if (ones > 0) return n - ones;
        
        int minLen = INT_MAX;
        for (int i = 0; i < n; i++) {
            int g = nums[i];
            for (int j = i; j < n; j++) {
                g = gcd(g, nums[j]);
                if (g == 1) {
                    minLen = min(minLen, j - i + 1);
                    break; // no need to extend further
                }
            }
        }
        
        return (minLen == INT_MAX) ? -1 : (minLen - 1) + (n - 1);
    }
};