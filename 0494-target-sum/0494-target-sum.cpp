class Solution {
public:
    map<vector<int>,int> memo;
    int fun(int index,int sum,int n,int target,vector<int>&nums){
        if(index==n){
            if(sum==target){
                return 1;
            }
            else
                return 0;
        }
        auto curr ={index,sum};
        if(memo.find(curr)!=memo.end()){
            return memo[curr];
        }
        int add=fun(index+1, sum+nums[index],n,target,nums);
        int sub=fun(index+1, sum- nums[index],n,target,nums);
        memo[curr]= add+sub;
        return memo[curr];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return fun(0,0,n,target,nums);
    }
};