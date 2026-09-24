class Solution {
public:
    int sumDigits(int n){
        int total=0;
        while(n){
            total+=n%10;
            n=n/10;
        }
        return total;
    }
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(sumDigits(nums[i])==i)
                return i;
        }
        return -1;
    }
};