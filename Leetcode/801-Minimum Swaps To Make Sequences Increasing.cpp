class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int length = A.size();
        int dp[length][2];
        memset(dp,0,sizeof(int)*2*length);
        dp[0][1] = 1;
        for(int i=1;i<length;i++)
        {
            dp[i][0] = dp[i][1] = 100000;
            if(A[i]>A[i-1] && B[i]>B[i-1])
            {
                // Swap at i, cause A[i-1] and B[i-1] swaped
                dp[i][1] =min(dp[i][1],dp[i-1][1]+1);
                // Not swap at i, cause A and B not swap
                dp[i][0] =min(dp[i][0],dp[i-1][0]);
            }
            if(A[i]>B[i-1] && B[i]>A[i-1])
            {
                // Swap at i, cause A[i-1] and B[i-1] not swapped
                dp[i][1] =min(dp[i][1],dp[i-1][0]+1);
                // Not swap at i, cause A[i-1] and B[i-1] swapped
                dp[i][0] =min(dp[i][0],dp[i-1][1]);
            }
        }
        return min(dp[length-1][1],dp[length-1][0]);
    }
};