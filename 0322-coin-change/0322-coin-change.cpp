class Solution {
public:
    int rec(int amount,map<int,int>&memo, vector<int>&coins){
        if(memo.find(amount)!=memo.end())
            return memo[amount];
        int ans=INT_MAX;
        for(int c:coins){
            if(c<=amount){
                int r=rec(amount-c,memo,coins);
                if(r!=-1)
                    ans=min(ans,r+1);
            }
        }
        memo[amount]=(ans==INT_MAX?-1:ans);
        return memo[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        map<int,int>memo;
        memo[0]=0;   //for n=0, number of coins=0
        return rec(amount,memo,coins);
    }
};