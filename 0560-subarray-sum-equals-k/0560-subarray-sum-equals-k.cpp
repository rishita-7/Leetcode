class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       unordered_map<int,int>freq;
       int sum=0;
       int res=0;
       freq[0]=1;    // empty subarray
       for(int a:nums){
            sum+=a;
            int f=freq[sum-k];
            res+=f;
            freq[sum]++;
       }
       return res;
    }
};