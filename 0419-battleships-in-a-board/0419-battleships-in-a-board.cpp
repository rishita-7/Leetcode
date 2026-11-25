class Solution {
public:
    int x[4]={-1,0,1,0};
    int y[4]={0,1,0,-1};

    bool isValid(int m, int n,int i, int j){
        if(i<0 || j<0 || i>=m || j>=n) return false;
        return true;
    }

    void dfs(vector<vector<char>>&board,vector<vector<bool>>&vis,int i,int j,int m,int n){
        vis[i][j]=true;
        for(int k=0;k<4;k++){
            int r=i+x[k];
            int c=j+y[k];
            if(isValid(m,n,r,c) && board[r][c]=='X' && vis[r][c]==false){
                dfs(board,vis,r,c,m,n);
            }
        }
        return;
    }
    int countBattleships(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='X' && visited[i][j]==false){
                    dfs(board,visited,i,j,m,n);
                    count++;
                }
            }
        }
        return count;
    }
};