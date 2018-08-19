class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int length = nums.size();
        
        std::set<int> s(std::make_move_iterator(nums.begin()), std::make_move_iterator(nums.end()));
        
        if(s.size()<3) return false;
        for(int i=0;i<length;i++)
            for(int j=i+1;j<length;j++)
            {
                if(nums[i]<nums[j])
                {
                    for(int k=j+1;k<length;k++)
                    {
                        if(nums[k]>=nums[j]) {j=k;continue;}
                        else
                        {
                            if(nums[k]>nums[i] && nums[j]>nums[k]) return true;
                        }
                    }
                    
                }           
            }
        return false;
    }
};