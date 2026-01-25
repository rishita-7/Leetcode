class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int min_difference=INT_MAX;
        for(int i=0;i<=nums.size()-k;i++){
            int curr_diff=nums[i+k-1]-nums[i];

            min_difference=min(min_difference,curr_diff);
        }
        return min_difference;
    }
};