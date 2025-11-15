class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
       set<int>s;
       vector<int>ans;
       for(int a:nums){
        if(!s.count(a)){
            s.insert(a);
        }
        else{
            ans.push_back(a);
        }
       }
       for(int i=1;i<=nums.size();i++){
        if(!s.count(i))
            ans.push_back(i);
       }
       return ans;
    }
};