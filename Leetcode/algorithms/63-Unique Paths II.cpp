class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int dp[102][102];
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        memset(dp,0,sizeof(int)*102*102);
        bool isObs = false;
        
        dp[0][0] = 1-obstacleGrid[0][0];
        dp[m-1][n-1] = 1-obstacleGrid[m-1][n-1];
        if(dp[0][0]==0 || dp[m-1][n-1]==0) return 0;
        
        
        for(int i=1;i<m;i++)
        {
            if(obstacleGrid[i][0]== 0)dp[i][0]=dp[i-1][0];
            else dp[i][0]=0;
        }
        for(int i=1;i<n;i++)
        {
            if(obstacleGrid[0][i]== 0)dp[0][i]=dp[0][i-1];
            else dp[0][i]=0;
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
            
                if(obstacleGrid[i][j]==0) dp[i][j] = dp[i-1][j]+dp[i][j-1];
                else dp[i][j]=0;
            }
        }
        return dp[m-1][n-1];
    }
};