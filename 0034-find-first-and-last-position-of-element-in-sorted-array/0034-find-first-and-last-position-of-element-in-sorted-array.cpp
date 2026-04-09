class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int i=0,j=n-1;
        while (i<n && nums[i]!=target)
            i++;
        while (j>=0 && nums[j]!=target)
            j--;
        if(i>j)
            return {-1,-1};
        return {i,j};
    }
};