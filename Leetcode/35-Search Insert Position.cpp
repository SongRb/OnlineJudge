class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int length=nums.size();
        for(int i=0;i<length;i++)
        {
            if(nums[i]==target) return i;
            else if(nums[i]>target) return i;
        }
        return length;
    }
};