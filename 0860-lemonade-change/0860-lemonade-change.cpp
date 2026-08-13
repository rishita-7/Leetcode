class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int>freq;
        for(int b:bills){
            if(b==5)
                freq[5]++;
            else if(b==10){
                freq[10]++;
                freq[5]--;
                if(freq[5]<0) return false;
            }
            else{
                if(freq[10]){
                    freq[10]--;
                    freq[5]--;
                    if(freq[5]<0) return false;
                }
                else{
                    freq[5]-=3;
                    if(freq[5]<0) return false;
                }

            }
        }
        return true;
    }
};