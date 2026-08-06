class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        for(int n:nums){
            if(n!=0){
                nums[i]=n;
                i++;
            }
        }
        while(i<n){
            nums[i]=0;
            i++;
        }
    }
};