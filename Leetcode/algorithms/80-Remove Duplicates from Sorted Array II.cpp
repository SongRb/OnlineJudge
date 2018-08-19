class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int length = nums.size();
        int idx = -1;
        for(int i=0;i<length;i++)
        {
            if(nums[i]==nums[idx])
            {
                if(idx==0 || nums[idx]!=nums[idx-1]) nums[++idx] = nums[i];
            }
            else
            {
                nums[++idx] = nums[i];
            }
        }
        return idx+1;
    }
};