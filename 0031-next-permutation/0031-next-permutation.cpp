class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int breaking_point=-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                breaking_point=i;
                break;
            }
        }
        if(breaking_point==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i=n-1;i>=0;i--){
            if(nums[i]>nums[breaking_point]){
                swap(nums[i],nums[breaking_point]);
                break;
            }
        }
        reverse(nums.begin()+breaking_point +1, nums.end());
        return;
    }
};