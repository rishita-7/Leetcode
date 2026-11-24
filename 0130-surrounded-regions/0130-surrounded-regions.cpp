class Solution {
public:
    int m,n;
    void dfs(vector<vector<char>> &board, int i,int j,vector<vector<bool>>&visited){
        if(i<0 || j<0 || i>=m || j>=n||  board[i][j]!='O' || visited[i][j]) return;
        board[i][j]='*';
        visited[i][j]=true;
        dfs(board,i+1,j,visited);
        dfs(board,i-1,j,visited);
        dfs(board,i,j+1,visited);
        dfs(board,i,j-1,visited);
    }
    void solve(vector<vector<char>>& board) {
        m=board.size();
        n=board[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            if(board[i][0]=='O' && !visited[i][0])
                dfs(board,i,0,visited);
            if(board[i][n-1]=='O' && !visited[i][n-1])
                dfs(board,i,n-1,visited);
        }
        for(int j=0;j<n;j++){
            if(board[0][j]=='O' && !visited[0][j])
                dfs(board,0,j,visited);
            if(board[m-1][j]=='O' && !visited[m-1][j])
                dfs(board,m-1,j,visited);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O')
                    board[i][j]='X';
                if(board[i][j]=='*')
                    board[i][j]='O';
            }
        }
        return;
    }
};