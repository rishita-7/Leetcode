class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        int total=m*n;
        vector<int>oneD;
        for(auto r:grid){
            for(int c:r){
                oneD.push_back(c);
            }
        }
        k=k%total;
        vector<int>rotated(oneD.end()-k,oneD.end());
        rotated.insert(rotated.end(),oneD.begin(),oneD.end()-k);

        vector<vector<int>>res(m,vector<int>(n));
        for(int i=0;i<total;i++){
            res[i/n][i%n]=rotated[i];
        }
        return res;
    }
};