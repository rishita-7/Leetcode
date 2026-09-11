class Solution {
public:
    int findFirst(vector<int>nums,int target){
        int low=0,high=nums.size()-1;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(target==nums[mid]){
                ans=mid;
                high=mid-1;
            }
            else if(target<nums[mid])
                high=mid-1;
            else
                low=mid+1;
        }
        return ans;
    }
    int findLast(vector<int>nums,int target){
        int low=0,high=nums.size()-1;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(target==nums[mid]){
                ans=mid;
                low=mid+1;
            }
            else if(target<nums[mid])
                high=mid-1;
            else
                low=mid+1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int i=findFirst(nums,target);
        int j=findLast(nums,target);
        return {i,j};
    }
};