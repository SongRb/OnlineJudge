class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        long long int m = grid.size();
        long long int n = grid[0].size();
        
        long long int **dp;
        dp = new long long int*[m];
        for(long long int i=0;i<m;i++)
        {
            dp[i] = new long long int[n];
        }

        dp[0][0] = (long long int)grid[0][0];
        for(int i=1;i<m;i++)
        {
            dp[i][0] = dp[i-1][0]+(long long int)grid[i][0];
        }
        for(int i=1;i<n;i++)
        {
            dp[0][i] = dp[0][i-1]+(long long int)grid[0][i];
        }
        
        for(int i=1;i<m;i++)
            for(long long int j=1;j<n;j++)
            {
                dp[i][j] = min(dp[i-1][j],dp[i][j-1])+(long long int)grid[i][j];
            }
        return (int)dp[m-1][n-1];
    }
};