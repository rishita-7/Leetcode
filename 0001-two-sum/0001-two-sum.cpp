class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>index;
        for(int i=0;i<nums.size();i++){
            index[nums[i]]=i;
        }
        int n=nums.size();
        for(int i=0;i<n;i++){
            int a=target-nums[i];
            if(index[a]!=i && index.count(a))
                return {index[a],i};
        }
        return {};
    }
};