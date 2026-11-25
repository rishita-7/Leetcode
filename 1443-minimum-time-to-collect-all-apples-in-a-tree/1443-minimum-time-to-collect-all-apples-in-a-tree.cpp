class Solution {
public:

    vector<bool>hasAppleGlobal;
    int dfs(int curr,int parent, vector<vector<int>>&adj){
        int total=0;
        for(auto a:adj[curr]){
            if(a==parent) continue;
            total+=dfs(a,curr,adj);
        }
        if(curr!=0 && (total>0 || hasAppleGlobal[curr]))
            return total+2;
        return total;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>>adj(n);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        hasAppleGlobal=hasApple;
        return dfs(0,-1,adj);
    }
};