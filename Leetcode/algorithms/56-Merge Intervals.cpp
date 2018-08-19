/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        map<int,int> mp;
        for(const auto& inv: intervals)
        {
            mp[inv.start] = max(mp[inv.start],inv.end);
        }
        vector<Interval> result;
        auto it = mp.begin();
        while(it!=mp.end())
        {
            auto tmp = it;
            tmp++;
            int first=it->first, second= it->second;
            while(tmp!=mp.end() && tmp->first<=second)
            {
                second = max(second, tmp->second);
                tmp++;
            }
            result.emplace_back(first, second);
            it = tmp;
        }
        return result;
    }
};