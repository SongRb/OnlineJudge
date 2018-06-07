class Solution {
public:
    // A string can be
    vector<int> getStringHash(const string& str)
    {
        vector<int> vec(26,0);
        for(const auto& ch: str)
        {
            vec[ch-'a']++;
        }
        return vec;
    }
    
    std::size_t operator()(std::vector<uint32_t> const& vec) const {
        std::size_t seed = vec.size();
        for(auto& i : vec) {
            seed ^= i + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<int, vector<pair<vector<int>,vector<string>>>> sss;
        vector<vector<string>> result;
        for(const auto& word:strs)
        {
            auto& vp = sss[word.size()];
            auto v = getStringHash(word);
            // p is a reference for a vector(may be empty)
            bool exist = false;
            for(auto& p:vp)
            {
                if(p.first==v)
                {
                    p.second.push_back(word);
                    exist = true;
                }
            }
            if(!exist)
            {
                vp.push_back(make_pair(v,vector<string>({word})));
            } 
        }
        for(const auto& id:sss)
        {
            for(const auto& p:id.second)
            {
                result.push_back(move(p.second));
            }
        }
        return result;
    }
};