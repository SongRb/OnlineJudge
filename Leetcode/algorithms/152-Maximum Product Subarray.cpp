class Solution {
public:
    int maxProduct(vector<int>& nums) {        
        int maxVal = nums[0];
        int minVal = nums[0];
        int res = nums[0];
        
        for(int i=1; i<nums.size(); i++)
        {
            int t1 = maxVal * nums[i];
            int t2 = minVal * nums[i];
            maxVal = max(max(t1, t2), nums[i]);
            minVal = min(min(t1, t2), nums[i]);
            res = max(maxVal, res);
        }
        return res;
    }
};