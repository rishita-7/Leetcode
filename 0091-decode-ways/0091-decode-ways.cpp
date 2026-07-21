class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        vector<int>dp(n+1,0);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            if(s[i-1]!='0')
                dp[i]=dp[i-1];

            // 2-digit decoding:-> if previous digit=1-> any digit will work
            // if previous digit=2 -> only 0 to 6 (20->26)
            if(i>1 && (s[i-2]=='1' || (s[i-2]=='2' && s[i-1]<='6'))){
                dp[i]+=dp[i-2];
            }
        }
        return dp[n];
    }
};