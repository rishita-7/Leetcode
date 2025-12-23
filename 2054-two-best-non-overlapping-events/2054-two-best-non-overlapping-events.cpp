#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](auto &a, auto &b){
            return a[1] < b[1]; 
        });

        int n = events.size();
        vector<int> best(n); 
        best[0] = events[0][2];

        for (int i = 1; i < n; i++) {
            best[i] = max(best[i-1], events[i][2]);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int val = events[i][2];
            int start = events[i][0];
            int lo = 0, hi = i - 1, idx = -1;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (events[mid][1] < start) {
                    idx = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }

            if (idx != -1) {
                ans = max(ans, val + best[idx]);
            }
            ans = max(ans, val); 
        }

        return ans;
    }
};
