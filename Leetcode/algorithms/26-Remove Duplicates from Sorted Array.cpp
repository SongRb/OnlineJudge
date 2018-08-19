class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int length = nums.size();
        if(length==0) return 0;
        int prev = nums[0];
        nums.push_back(nums[0]);
        int currentLength = 1;
        for(int i=1;i<length;i++)
        {
            if(nums[currentLength-1] == nums[length-1]) return currentLength;
            if(prev==nums[i])
            {
                nums[length] = nums[i];
            }
            else
            {
                nums[currentLength++] = nums[i];
                prev = nums[i];
            }
        }
        return currentLength;
    }
};