class Solution {
public:
    int rob(vector<int>& nums) {
        // vector<vector<int>> dp(nums.size(), vector<int>(2));
        vector<int> dp(2);
        if(nums.size()>2)
        {
            dp[0] = nums[0];
            dp[1] = nums[0]+nums[2];
            for(int i=3;i<nums.size();i++)
            {
                int tmp = dp[0];
                dp[0] = max(dp[0], dp[1]);
                dp[1] = tmp+nums[i];
            }
            int best = dp[0];
            // do not rob first house
            dp[0] = 0;
            dp[1] = nums[1];
            // index 1 can rob and not rob
            for(int i=2;i<nums.size();i++)
            {
                int tmp = dp[0];
                dp[0] = max(dp[0], dp[1]);
                dp[1] = tmp+nums[i];
            }   
            return max(best, max(dp[1], dp[0]));
        }
        else if(nums.size()==0) return 0;
        else 
        {
            return *max_element(nums.begin(), nums.end());
        }
    }
};