class Solution {
public:
    int count=0;
    void fun(int index,int sum,int n,int target,vector<int>&nums){
        if(index==n){
            if(sum==target){
                count++;
                return;
            }
            else
                return;
        }
        fun(index+1, sum+nums[index],n,target,nums);
        fun(index+1, sum- nums[index],n,target,nums);
        return;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        fun(0,0,n,target,nums);
        return count;
    }
};