class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        const int MOD = 1'000'000'007;
        int n = nums.size();
        vector<int> dp(n + 1, 0), pref(n + 1, 0);
        dp[0] = 1;
        pref[0] = 1;

        deque<int> dqMax, dqMin;
        int L = 0;

        for (int i = 0; i < n; i++) {
            while (!dqMax.empty() && nums[dqMax.back()] <= nums[i]) dqMax.pop_back();
            dqMax.push_back(i);
            while (!dqMin.empty() && nums[dqMin.back()] >= nums[i]) dqMin.pop_back();
            dqMin.push_back(i);

            while (!dqMax.empty() && !dqMin.empty() &&
                   nums[dqMax.front()] - nums[dqMin.front()] > k) {
                if (dqMax.front() == L) dqMax.pop_front();
                if (dqMin.front() == L) dqMin.pop_front();
                L++;
            }

            int left = L, right = i;
            long long ways = pref[right] - (left > 0 ? pref[left - 1] : 0);
            ways %= MOD;
            if (ways < 0) ways += MOD;

            dp[i + 1] = (int)ways;
            pref[i + 1] = (pref[i] + dp[i + 1]) % MOD;
        }

        return dp[n];
    }
};
