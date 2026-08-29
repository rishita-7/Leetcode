class Solution {
public:
    int x[4]={-1,0,1,0};
    int y[4]={0,1,0,-1};
    bool isvalid(int i,int j,int m,int n){
        if(i<0 || i>=m || j<0 || j>=n)
            return false;
        return true;
    }
    void dfs(vector<vector<char>>&grid,vector<vector<bool>>&vis,int i,int j,int m,int n){
        vis[i][j]=true;
        for(int k=0;k<4;k++){
            int r=i+x[k];
            int c=j+y[k];
            if(isvalid(r,c,m,n) && grid[r][c]=='1' && vis[r][c]==false){
                dfs(grid,vis,r,c,m,n);
            }
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && visited[i][j]==false){
                    dfs(grid,visited,i,j,m,n);
                    count++;
                }
            }
        }
        return count;
    }
};