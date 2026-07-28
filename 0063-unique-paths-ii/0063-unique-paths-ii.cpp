class Solution {
public:
int rec(int m,int n,map<pair<int,int>,int>&d,vector<vector<int>>& obstacleGrid){
        if(m<0 || n<0)
            return 0;
        if(obstacleGrid[m][n]==1)
            return 0;
        if(m==0 && n==0)
            return 1;
        if(d.find({m,n})!=d.end())
            return d[{m,n}];
        int B=rec(m-1,n,d,obstacleGrid);
        int R=rec(m,n-1,d,obstacleGrid);
        d[{m,n}]=B+R;
        return B+R;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
         map<pair<int,int>,int>d;
        return rec(m-1,n-1,d,obstacleGrid);
    }
};