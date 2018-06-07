class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int length = nums.size();
        int max = accumulate(nums.begin(), nums.end(), 0);
        // dp[i][j]: up to position i, ways that the sum is j+max;
        vector<unordered_map<int,int>> dp(length, unordered_map<int,int>());
        dp[0][-nums[0]] += 1;
        dp[0][nums[0]] += 1;
        for(int i=1;i<length;i++)
        {
            for(const auto& p:dp[i-1])
            {
                dp[i][p.first-nums[i]]+=p.second;
                dp[i][p.first+nums[i]]+=p.second;
            }
        }
        return dp[length-1][S];                       
    }
};