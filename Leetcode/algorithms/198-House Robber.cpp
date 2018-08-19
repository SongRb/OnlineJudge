class Solution {
public:
    int rob(vector<int>& nums) {
        int dp[10000][2];
        memset(dp,0,10000*2);

        int length = nums.size();
        if(length == 0) return 0;
        else if(length == 1) return nums[0];
        dp[0][1] = nums[0];
        dp[0][0] = 0;
        for(int i=1;i<length;i++)
        {
            dp[i][1]  = dp[i-1][0]+nums[i];
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
        }
        return max(dp[length-1][0],dp[length-1][1]);
    }
};