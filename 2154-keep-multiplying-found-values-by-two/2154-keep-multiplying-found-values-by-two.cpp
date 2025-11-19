class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(),nums.end());
        for(int a:nums){
            if (a==original){
                original*=2;
            }
        }
        return original;
    }
};