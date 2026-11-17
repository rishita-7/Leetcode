class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<vector<int>>dist(m+1,vector<int>(n+1));
        for(int i=0;i<=m;i++)
            dist[i][0]=i;
        for(int j=0;j<=n;j++)
            dist[0][j]=j;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1])
                    dist[i][j]=dist[i-1][j-1];
                else
                    dist[i][j]=1+ min(dist[i-1][j],min(dist[i][j-1],dist[i-1][j-1]));
            }
        }
        return dist[m][n];
    }
};