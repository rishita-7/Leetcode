class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n=grid.size();
        //step-1: count the number of trailing zeros in each row
        vector<int>trailing;
        for(auto row:grid){
            int count=0;
            for(int j=n-1;j>=0;j--){
                if(row[j]==0)
                    count++;
                else 
                    break;
            }
            trailing.push_back(count);
        }
        //Step-2: Processing each row
        int swaps=0;
        for(int i=0;i<n;i++){
            //required trailing zeros for this row
            int req=n-i-1;
            //find a row j>=i with enough zeros
            int j=i;
            while(j<n && trailing[j]<req){
                j++;
            }
            //if no such row found, return -1
            if(j==n)
                return -1;

            swaps+=j-i;

            // step-3: Bring that row up (swapping with the previous rows)
            while(j>i){
                int temp = trailing[j];
                trailing[j] = trailing[j - 1];
                trailing[j - 1] = temp; 
                j--;
            }
        }
        return swaps;
    }
};