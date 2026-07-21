class Solution {
public:
    int rec(int n){
        if (n<=1)
            return 1;
        int total=0;
        for(int i=1;i<=n;i++){
            int left=rec(i-1);
            int right=rec(n-i);
            total+= (left*right);
        }
        return total;
    }
    int numTrees(int n) {
        return rec(n);
    }
};