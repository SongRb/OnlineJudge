class Solution {
public:
    int length;
    vector<vector<int>> result;
    void search(const vector<int>& nums, vector<int> subset)
    {
        int slength = subset.size();
        vector<int> res;
        for(const auto& idx: subset) res.push_back(nums[idx]);
        result.push_back(res);
        if(slength==length) return;
        auto i = subset.empty()?0:subset[slength-1]+1;
        for(;i<length;i++)
        {
            subset.push_back(i);
            search(nums, subset);
            subset.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        length = nums.size();
        vector<int> subset;
        search(nums, subset);
        return result;
    }
};