class Solution {
public:
    void dfs(vector<vector<int>>&grid,int i, int n,vector<bool>&visited){
        visited[i]=true;
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1 && !visited[j]) {
                dfs(grid,j,n, visited);
            }
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool>visited(n,false);
        int provinces=0;
        for(int i=0;i<n;i++){
                if(visited[i]==false){
                    dfs(isConnected,i,n,visited);
                    provinces++;
                }
        }
        return provinces;
    }
};