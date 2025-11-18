class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i=0;
        while(i<bits.size()-1){
            if(bits[i]==1)
                i+=2;
            else
                i+=1;
        }
        return i==bits.size()-1;
    }
};

/*
Approach:-
    if you encounter '0'-> move one step
    if you encounter '1'-> move two steps
    if the last bit is encountered, this means the last character is one-bit
    and if the last character is skipped, then the last character is a part of 2-bit character
*/
