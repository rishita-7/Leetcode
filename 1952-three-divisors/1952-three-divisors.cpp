class Solution {
public:
    int divisor_count(int n){
        int count=0;
        for(int i=1;i<=n;i++){
            if(n%i==0){
                count++;
            }
        }
        return count;
    }
    bool isThree(int n) {
        int div= divisor_count(n);
        if(div==3)
            return true;
        return false;
    }
};