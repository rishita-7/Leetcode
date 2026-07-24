class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int maxLeft=height[0];
        int maxRight=height[n-1];
        unordered_map<int,int> left_max;
        unordered_map<int,int> right_max;
        for(int i=0;i<n;i++){
            maxLeft=max(maxLeft,height[i]);
            left_max[i]=maxLeft;
        }
        for(int i=n-1;i>=0;i--){
            maxRight=max(maxRight,height[i]);
            right_max[i]=maxRight;
        }
        int count=0;
        for(int i=0;i<n;i++){
            int minHeight=min(left_max[i],right_max[i]);
            count+= (minHeight-height[i]);
        }
        return count;
    }
};