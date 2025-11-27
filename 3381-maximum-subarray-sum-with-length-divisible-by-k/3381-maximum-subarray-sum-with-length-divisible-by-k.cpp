class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
         int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        vector<long long> minPrefix(k, LLONG_MAX);
        minPrefix[0] = 0;
        long long ans = LLONG_MIN;
        for (int i = 1; i <= n; i++) {
            int r = i % k;
            if (minPrefix[r] != LLONG_MAX) {
                ans = max(ans, prefix[i] - minPrefix[r]);
            }
            minPrefix[r] = min(minPrefix[r], prefix[i]);
        }
        return ans;
    }
};