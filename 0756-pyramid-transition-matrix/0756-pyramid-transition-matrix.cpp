
class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        // Build mapping: (X,Y) -> list of possible Z
        unordered_map<string, vector<char>> mp;
        for (auto &a : allowed) {
            string key = a.substr(0, 2);
            mp[key].push_back(a[2]);
        }

        unordered_map<string, bool> memo; // memoization

        function<bool(string)> dfs = [&](string row) {
            if (row.size() == 1) return true;
            if (memo.count(row)) return memo[row];

            // Generate all possible next rows
            vector<string> nextRows;
            function<void(int, string)> buildNext = [&](int i, string path) {
                if (i == row.size() - 1) {
                    if (dfs(path)) {
                        memo[row] = true;
                        return;
                    }
                } else {
                    string key = row.substr(i, 2);
                    if (mp.count(key)) {
                        for (char c : mp[key]) {
                            buildNext(i + 1, path + c);
                            if (memo.count(row) && memo[row]) return; // early stop
                        }
                    }
                }
            };

            buildNext(0, "");
            if (!memo.count(row)) memo[row] = false;
            return memo[row];
        };

        return dfs(bottom);
    }
};
