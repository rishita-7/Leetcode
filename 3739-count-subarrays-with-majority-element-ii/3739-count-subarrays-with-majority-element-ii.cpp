class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> prefix(n+1, 0);
        
        for (int i = 0; i < n; i++) {
            prefix[i+1] = prefix[i] + (nums[i] == target ? 1 : -1);
        }
        
        // Coordinate compression
        vector<int> all = prefix;
        sort(all.begin(), all.end());
        all.erase(unique(all.begin(), all.end()), all.end());
        
        auto getIndex = [&](int x) {
            return (int)(lower_bound(all.begin(), all.end(), x) - all.begin()) + 1;
        };
        
        vector<int> BIT(all.size()+2, 0);
        auto update = [&](int idx) {
            for (; idx < BIT.size(); idx += idx & -idx) BIT[idx]++;
        };
        auto query = [&](int idx) {
            long long sum = 0;
            for (; idx > 0; idx -= idx & -idx) sum += BIT[idx];
            return sum;
        };
        
        long long ans = 0;
        for (int p : prefix) {
            int idx = getIndex(p);
            ans += query(idx-1); // count of prefix < current
            update(idx);
        }
        return ans;
    }
};

