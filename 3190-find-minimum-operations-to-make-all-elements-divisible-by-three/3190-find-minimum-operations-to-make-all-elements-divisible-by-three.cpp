class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int max_op=0;
        for(int a:nums){
            if(a%3==1 || a%3==2)
                max_op++;
        }
        return max_op;
    }
};