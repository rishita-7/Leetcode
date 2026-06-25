class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        nums[0]=(nums[0]==target?1:-1);
        for(int i=1;i<nums.size();i++){
            nums[i]=nums[i-1]+(nums[i]==target?1:-1);
        }
        int total=0;
        for(int i:nums){
            if(i>0)
                total++;
        }
        for(int i=1;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                if(nums[j]-nums[i-1]>0)
                    total++;
            }
        }
        return total;
    }
};