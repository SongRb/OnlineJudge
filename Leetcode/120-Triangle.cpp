class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int length = triangle.size();
        vector<vector<int>> dp(length+1);
        dp[0]= vector<int>(1,0);
        for(int i=1;i<=length;i++)
        {
            dp[i] = vector<int>(i,0);
        }
        for(int i=1;i<=length;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(j==0) dp[i][j] = dp[i-1][j];
                else if(j==i-1) dp[i][j] = dp[i-1][j-1];
                else
                {
                    dp[i][j] = min(dp[i-1][j],dp[i-1][j-1]);
                }
                dp[i][j] += triangle[i-1][j];
            }
        }
        return *min_element(dp[length].begin(), dp[length].end());
    }
};