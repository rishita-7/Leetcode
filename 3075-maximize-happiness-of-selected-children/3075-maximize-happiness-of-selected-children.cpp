class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(),happiness.end(),greater<int>());
        long long ans=0;
        int n=happiness.size();
        int turns=0;
        for(auto a:happiness){
            ans+=max((a-turns),0);
            turns++;
            if(turns==k)
                break;
        }
        return ans;
    }
};