class Solution {
public:
    void divisors(vector<int>numsDivide,set<int>&s,int a){
        int m=*min_element(numsDivide.begin(),numsDivide.end());
        for(int i=1;i<=m && i<=a;i++){
            bool flag=true;
            for(int n:numsDivide){
                if (n%i!=0){
                    flag=false;
                    break;
                }
            }
            if (flag)
                s.insert(i);
        }
    }
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        set<int>s;
        divisors(numsDivide,s,nums[n-1]);
        int count=0;
        for(int n:nums){
            if(s.count(n)==0)
                count++;
            else
                break;
        }
        return (count==nums.size())?-1:count;
    }
};