class Solution {
public:
    int countOdds(int low, int high) {
        int total=(high-low)/2;
        if(high%2!=0 || low%2!=0)
            total++;
        return total;
    }
};