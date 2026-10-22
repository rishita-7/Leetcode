class Solution {
public:
    int solve(vector<int>&nums, int start, int end, int player1){
        if(start>end)
            return 0;
        if (player1){
            int choice1=nums[start] + solve(nums, start+1, end,0);
            int choice2=nums[end] + solve(nums, start, end-1, 0);
            return max(choice1,choice2);
        }
        else{
            int choice1= -nums[start] + solve(nums,start+1,end,1);
            int choice2= -nums[end] + solve(nums, start, end-1,1);
            return min(choice1,choice2);
        }
    }
    bool predictTheWinner(vector<int>& nums) {
        int res=solve(nums,0, nums.size()-1, 1); //turn=1 -> player1, turn=0 ->player2
        if (res>=0) return true;
        return false;
    }
};