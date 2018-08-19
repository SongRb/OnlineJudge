class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left=0, right = nums.size()-1;
        while(left<=right)
        {
            // cout<<left<<" "<<right<<endl;
            int pivot = (left+right)/2;
            if(nums[pivot]==target) return true;
            while(nums[left]==nums[pivot] && nums[pivot]==nums[right])
            {
                left++; right--;
            }
            if(nums[left]<=nums[pivot])
            {
                if(target>=nums[left] && nums[pivot]>target)
                {
                    right = pivot-1;
                }
                else
                {
                    left = pivot+1;
                }
            }
            else
            {
                if(target>nums[pivot] && nums[right]>=target)
                {
                    left = pivot+1;
                }
                else
                {
                    right = pivot-1;
                }
            }
        }
        return false;
    }
};