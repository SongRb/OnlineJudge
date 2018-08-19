
class Solution {
public:
	Solution(){}

	int maxCoins(vector<int>& nums) {
		int length = nums.size();

		vector<int> ballon;
		ballon.push_back(1);
		for (int i = 0; i < length; i++)
		{
			if (nums[i] > 0) ballon.push_back(nums[i]);
		}
		ballon.push_back(1);
		length = ballon.size();
		
		int** dp;
		dp = new int*[length];
		for (int i = 0; i < length; i++)
		{
			dp[i] = new int[length];
			memset(dp[i], 0, sizeof(int)*length);
		}

		for (int k = 2; k < length; k++)
		{
			for (int left = 0; left < length - k; left++)
			{
				int right = left + k;
				for (int i = left + 1; i < right; i++)
				{
					dp[left][right] = max(dp[left][right],
						ballon[left] * ballon[i] * ballon[right] + dp[left][i] + dp[i][right]);
				}
			}
		}

		return dp[0][length-1];
	}
};
