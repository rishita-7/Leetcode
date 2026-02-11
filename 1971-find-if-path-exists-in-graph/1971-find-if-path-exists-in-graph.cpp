class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>>G;
        for(auto e:edges){
            G[e[0]].push_back(e[1]);
            G[e[1]].push_back(e[0]);
        }
        queue<int>q;
        vector<bool>visited(n,false);
        q.push(source);
        
        while(!q.empty()){
            int x=q.front();
            q.pop();
            if(x==destination)
                return true;
            visited[x]=true;
            for(int i:G[x]){
                if(!visited[i]){
                    visited[i]=true;
                    q.push(i);
                }
            }
        }
        return false;
    }
};