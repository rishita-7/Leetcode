class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long total_sum=0;
        for(auto & r:grid){
            for(auto val:r){
                total_sum+=val;
            }
        }
        if(total_sum % 2 != 0)
            return false;
        
        int row=grid.size();
        int col=grid[0].size();

        long long curr_sum=0;

        for(int i=0;i<row;i++){
            for(auto value:grid[i])
                curr_sum+=value;
            if((curr_sum==(total_sum/2)) && ((i+1)<row))
                return true;
        }
        curr_sum=0;
        
        for(int j=0;j<col;j++){
            for(int i=0;i<row;i++)
                curr_sum+=grid[i][j];
            if(curr_sum==total_sum/2 && j+1<col)
                return true;
        }
        return false;
    }
};