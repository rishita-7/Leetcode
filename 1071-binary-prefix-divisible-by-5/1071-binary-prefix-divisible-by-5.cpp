class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool>answer(nums.size());
        int rem=0;
        for(int i=0;i<nums.size();i++){
            int b=nums[i];
            rem=(rem*2+b)%5;
            if(rem==0)
                answer[i]=true;
            else
                answer[i]=false;
        }
        return answer;
    }
};