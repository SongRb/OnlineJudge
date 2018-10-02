class Solution {
public:    
    int findMin(vector<int>& nums) {
        int p = -1;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]>nums[i+1]) p = i;
        }
        return min(nums[nums.size()-1], min(nums[0], nums[p+1]));
    }
};