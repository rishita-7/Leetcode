class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        vector<int>pre(n);
        unordered_map<int,int>freq;
        freq[0]=1;
        pre[0]=nums[0];
        for(int i=1; i<n;i++){
            pre[i]=nums[i]+pre[i-1];
        }
        int count=0;
        for(int i=0;i<n;i++){
            int extra=pre[i]-goal;
            if(freq.find(extra)!=freq.end())
                count+=freq[extra];
            freq[pre[i]]++;
        }
        return count;
    }
};