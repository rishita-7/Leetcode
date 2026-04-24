class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int r=0,l=0;
        for(char c:moves){
            if (c=='L')
                l++;
            else if(c=='R')
                r++;
        }
        char a='R';
        if(l>=r)
            a='L';
        int count=0;
        for(int i=0;i<moves.size();i++){
            if(moves[i]==a || moves[i]=='_')
                count++;
            else
                count--;
        }
        return abs(count);
    }
};