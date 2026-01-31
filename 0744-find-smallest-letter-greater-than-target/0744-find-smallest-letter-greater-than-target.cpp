class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n=letters.size();
        int low=0,high=n-1,mid;
        int ans=0;
        while(low<=high){
            mid=(low+high)/2;
            if (letters[mid]>target){
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return letters[ans];
    }
};