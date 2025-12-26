class Solution {
public:
    int bestClosingTime(string customers) {
        int score=0;
        int max_score=0;
        int earliest_hour=0;
        for(int i=0;i<customers.size();i++){
            score+=(customers[i]=='Y')?1:-1;
            if(score>max_score){
                max_score=score;
                earliest_hour=i+1;
            }
        }
        return earliest_hour;
    }
};