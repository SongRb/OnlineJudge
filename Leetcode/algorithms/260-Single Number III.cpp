class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        if(nums.size()==0) return {0,0};
        else if(nums.size()==1) return {nums[0], 0};
        unordered_map<int, int> counter;
        for(const auto& num: nums)
        {
            counter[num]++;
        }
        vector<int> result;
        
        for(const auto& num:counter)
        {
            cout<<num.first<<" "<<num.second<<endl;
            if(num.second==1) result.push_back(num.first);
        }
        return result;
    }
};