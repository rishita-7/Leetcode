class Solution {
private:
    int count_comp(int n, vector<vector<int>>& connections){
        vector<vector<int>>adj(n);
        for(auto e:connections){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool>visited(n,false);
        int components=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                visited[i]=true;
                components++;
                queue<int>q;
                q.push(i);
                while(!q.empty()){
                    int node = q.front();
                    q.pop();

                    for (int neighbor : adj[node]) {
                        if (!visited[neighbor]) {
                            visited[neighbor] = true;
                            q.push(neighbor);
                        }
                    }
                }
            }
        }
        return components;
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int edges=connections.size();
        if(edges<n-1)
            return -1;
        int components=count_comp(n,connections);
        return components-1;
    }
};