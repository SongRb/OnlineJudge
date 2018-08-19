class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> acc;
        int length=nums.size();
        acc.push_back(nums[0]);
        int maxVal=nums[0], minVal=nums[0], best=nums[0];
        for(int i=1;i<length;i++)
        {
            acc.push_back(acc[i-1]+nums[i]);
            minVal=min(acc[i-1],minVal);
            best=max(best,acc[i]-minVal);
            best=max(best,acc[i]);
        }
        return best;     
        
    }
};