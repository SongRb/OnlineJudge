class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index = -1;
        int length = nums.size();
        for(int i=0;i<length;i++)
        {
            if(i<length-1 && nums[i]<nums[i+1])
            {
                index = i;
            }
        }
        if(index==-1)
        {
            reverse(nums.begin(), nums.end());
        }
        else
        {
            int end=index+1;
            for(int i=index+1; i<length; i++)
            {
                if(nums[i]>nums[index]) end=i;
            }
            swap(nums[index], nums[end]);
            reverse(nums.begin()+index+1, nums.end());
        }
    }
};