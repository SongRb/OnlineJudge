static const auto io_speed_up = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();


class Solution {
public:
    vector<vector<int>> result;
    map<int,int> mp;
    
    void rec(vector<int>& res, int target)
    {
        if(target==0)
        {
            result.push_back(res);
        }
        else if(target>0)
        {
            for(auto& p:mp)
            {
                if(p.first>target) break;
                int resLen = res.size();
                if(p.second>0 && p.first<=target && (resLen==0 || p.first>=res[resLen-1]))
                {
                    res.push_back(p.first);
                    p.second--;
                    rec(res, target-p.first);
                    p.second++;
                    res.pop_back();
                }
            } 
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if(candidates.size()==0) return result;
        for(const auto& i:candidates) mp[i]++;
        vector<int> res;
        rec(res, target);
        return result;
    }
};