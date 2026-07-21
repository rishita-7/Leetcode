class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        if (s[0]=='0')
            return 0;
        if(n==1)
            return 1;
        vector<int>dp(n+1,0);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            //single character-> if the character is 0, dp[i] will remain 0, else the dp[prev character] will be copied
            if(s[i-1]!='0')
                dp[i]=dp[i-1];
            if (i>1 &&(s[i-2]=='1' || (s[i-2]=='2' && s[i-1]<='6')))
                dp[i]+=dp[i-2];
        }
        return dp[n];
    }
};