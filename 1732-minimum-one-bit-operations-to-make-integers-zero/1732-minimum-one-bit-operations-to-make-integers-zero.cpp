class Solution {
public:
    unordered_map<int, int> memo;
        
        int dfs(int x) {
            if (x == 0) return 0;
            if (memo.count(x)) return memo[x];
            
            int k = 31 - __builtin_clz(x); 
            int res = (1 << (k + 1)) - 1 - dfs(x ^ (1 << k));
            return memo[x] = res;
        }
    int minimumOneBitOperations(int n) {
        return dfs(n);
    }
};