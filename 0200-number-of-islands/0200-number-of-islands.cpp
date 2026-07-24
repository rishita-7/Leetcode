class Solution {
public:
    bool isValid(int row,int col, int m, int n){
        if(row<0 || row>=m || col<0 || col>=n)
            return false;
        return true;
    }
    void dfs(vector<vector<char>>&grid,int i,int j,int m,int n,vector<vector<bool>>&visited){
        visited[i][j]=true;
        int x[4]={-1,1,0,0};
        int y[4]={0,0,-1,1};
        for(int k=0;k<4;k++){
            int row=i+x[k];
            int col=j+y[k];
            if(isValid(row,col,m,n) && grid[row][col]=='1' && visited[row][col]==false){
                dfs(grid,row,col,m,n,visited);
            }
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int res=0;
        vector<vector<bool>>visited(m,vector<bool>(n));
        for (int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && visited[i][j]==false){
                    dfs(grid,i,j,m,n,visited);
                    res++;
                }
            }
        }
        return res;
    }
};