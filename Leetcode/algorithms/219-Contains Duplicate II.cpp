class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> mp;
        for(int i=0;i<nums.size();i++) 
            mp[nums[i]].push_back(i);
        for(auto& p: mp)
        {
            sort(p.second.begin(), p.second.end());
            for(int i=1;i<p.second.size();i++)
            {
                if(p.second[i]-p.second[i-1]<=k) 
                    return true;
            }
        }
        return false;
    }
};