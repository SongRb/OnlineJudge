class Solution {
public:
    int search(const vector<int> nums, int low, int target)
    {
        int left = low, right = nums.size()-1;
        if(nums[0] > target) return 0;
        else if(nums[nums.size()-1] < target) return nums.size();
        while(left<=right)
        {
            int pivot = (left + right)/2;
            if(nums[pivot] > target) right = pivot-1;
            else if(nums[pivot] < target) left = pivot+1;
            else return pivot;
        }
        return left;
    }
    
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int> acc(nums.size());
        acc[0] = nums[0];
        for(int i=1;i<nums.size();i++) acc[i] = acc[i-1]+nums[i];
        int best = nums.size()+1;
        for(int i=0;i<nums.size();i++)
        {
            // search starts from i, counting sum of(nums[i] ~ nums[idx])
            int idx = search(acc, i, acc[i]-nums[i]+s);
            if(idx==-1) continue;
            else if(idx==nums.size())
            {
                if(best==nums.size()+1) return 0;
                else return best;
            }
            else
            {
                best = min(best, idx-i+1);
            }
        }
        if(best==nums.size()+1) return 0;
        else return best;       
    }
};