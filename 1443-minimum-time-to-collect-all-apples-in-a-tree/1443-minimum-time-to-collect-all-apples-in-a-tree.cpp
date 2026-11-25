class Solution {
public:
    int dfs(int curr,int parent, vector<vector<int>>&adj,vector<bool>& hasApple){
        int total=0;
        for(auto a:adj[curr]){
            if(a==parent) continue;
            total+=dfs(a,curr,adj,hasApple);
        }
        if(curr!=0 && (total>0 || hasApple[curr]))
            return total+2;
        return total;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>>adj(n);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        return dfs(0,-1,adj,hasApple);
    }
};