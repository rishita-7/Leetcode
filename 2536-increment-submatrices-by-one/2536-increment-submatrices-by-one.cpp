class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> diff(n+1, vector<int>(n+1, 0));
        for (auto &q : queries) {
            int r1 = q[0], c1 = q[1], r2 = q[2], c2 = q[3];
            diff[r1][c1] += 1;
            if (c2 + 1 <= n) diff[r1][c2+1] -= 1;
            if (r2 + 1 <= n) diff[r2+1][c1] -= 1;
            if (r2 + 1 <= n && c2 + 1 <= n) diff[r2+1][c2+1] += 1;
        }
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (r > 0) diff[r][c] += diff[r-1][c];
                if (c > 0) diff[r][c] += diff[r][c-1];
                if (r > 0 && c > 0) diff[r][c] -= diff[r-1][c-1];
            }
        }
        vector<vector<int>> res(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] = diff[i][j];
            }
        }
        return res;
    }
};
