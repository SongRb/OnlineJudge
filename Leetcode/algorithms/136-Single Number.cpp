class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(const auto& num: nums) mp[num]++;
        for(const auto& p:mp) if(p.second==1) return p.first;
        return -1;
    }
};