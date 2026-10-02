class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int maxSum=nums[0];
       int ans=maxSum;
       for(int i=1;i<nums.size();i++){
            int v1=maxSum+nums[i];
            int v2=nums[i];
            maxSum=max(v1,v2);
            ans=max(maxSum,ans);
       }
       return ans;
    }
};