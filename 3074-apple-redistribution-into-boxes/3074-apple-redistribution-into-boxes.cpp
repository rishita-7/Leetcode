class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum=0;
        for(int a:apple)
            sum+=a;
        sort(capacity.begin(),capacity.end(),greater<int>());
        int count=0;
        for(int x:capacity){
            if(sum<=0)
                break;
            sum-=x;
            count++;
        }
        return count;
    }
};