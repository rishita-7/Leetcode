class Solution {
public:
    int findTheWinner(int n, int k) {
        return 1+ josephus_problem(n,k);
    }
    int josephus_problem(int n,int k){
        if(n==1)
            return 0;
        return (josephus_problem(n-1,k)+k)%n;
    }
};