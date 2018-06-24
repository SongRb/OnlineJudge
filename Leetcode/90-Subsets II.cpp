class Solution {
public:    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result = {{}};
        unordered_map<int, int> mp;
        for(const auto& i:nums) mp[i]++;
        for(const auto& p:mp)
        {
            int prevSize = result.size();
            for(int i=0;i<prevSize;i++)
            {
                auto instance = result[i];
                auto s = p.second;
                for(int j=1;j<=s;j++)
                {
                    instance.push_back(p.first);
                    result.push_back(instance);
                }
            }
        }
        return result;
    }
};