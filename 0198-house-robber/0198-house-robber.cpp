class Solution {
public:
    int dfs(int ind,vector<int>&nums,vector<int>&dp){
        int n=nums.size();
        if(ind>=n)
            return 0;
        if(dp[ind]!=-1) return dp[ind];
        int rob_current= nums[ind]+dfs(ind+2,nums,dp);
        int skip_current=dfs(ind+1,nums,dp);
        dp[ind]= max(rob_current,skip_current);
        return dp[ind];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return dfs(0,nums,dp);
    }
};