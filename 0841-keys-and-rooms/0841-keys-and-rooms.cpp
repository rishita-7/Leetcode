class Solution {
public:
    set<int>visited;
    void solve(int i,vector<vector<int>>& rooms){
        if(visited.count(i)!=0)
            return;
        visited.insert(i);
        for(int r:rooms[i])
            solve(r,rooms);
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        solve(0,rooms);
        if(visited.size()==n)
            return true;
        else
            return false;
    }
};