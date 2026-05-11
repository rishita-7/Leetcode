class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int sum=0;
        int f=1;
        for(int n:nums){
            if(f){
                sum+=n;
                f=0;
            }
            else{
                sum-=n;
                f=1;
            }
        }
        return sum;
    }
};