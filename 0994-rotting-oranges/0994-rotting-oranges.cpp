class Solution {
private:
    bool isValid(int i,int j, int m, int n){
        if(i<0 || i>=m || j<0 || j>=n)\
            return false;
        return true;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int x[4]= {-1,0,1,0};
        int y[4]= {0,1,0,-1};
        int fresh=0;
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                    fresh++;
                else if(grid[i][j]==2){
                    q.push({i,j});
                    grid[i][j]=-2;
                }
            }
        }
        if(fresh==0)
            return 0;
        int time=0;
        while(!q.empty()){
            int s=q.size();
            bool flag=false;
            while(s--){
                auto p=q.front();
                q.pop();
                int r=p.first;
                int c=p.second;
                for(int k=0;k<4;k++){
                    int row=r+x[k];
                    int col=c+y[k];
                    if(isValid(row,col,m,n) && grid[row][col]==1){
                        fresh--;
                        q.push({row,col});
                        grid[row][col]=-2;
                        flag=true;
                    }
                }
            }
            if(flag)
                time++;
        }
        if(fresh>0)
            return -1;
        return time;
    }
};