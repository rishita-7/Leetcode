class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> loserMap;
        for(auto match : matches){
            int winner=match[0];
            int loser=match[1];
            loserMap[loser]++;
            if(loserMap.find(winner)==loserMap.end())
                loserMap[winner]=0;
        }
        vector<int>neverLost;
        vector<int>lostOnce;
        for(auto p:loserMap){
            if(p.second==0)
                neverLost.push_back(p.first);
            else if(p.second==1)
                lostOnce.push_back(p.first);
        }
        sort(neverLost.begin(),neverLost.end());
        sort(lostOnce.begin(),lostOnce.end());
        return {neverLost,lostOnce};
    }
};