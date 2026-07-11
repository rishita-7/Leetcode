class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int left=0;
        int right=0;
        int total=0;
        for(int n:nums){
            total+=n;
        }
        int n=nums.size();
        for(int i=0;i<n;i++){
            right=total-left-nums[i];
            if(left==right)
                return i;
            left=left+nums[i];
        }
        return -1;
    }
};