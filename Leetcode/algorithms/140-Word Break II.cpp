class Solution {
public:
    unordered_map<string, vector<string>> mp;
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if(s.empty()) return vector<string>(1, s);
        if(wordDict.empty()) return vector<string>();

        dfs(s, wordDict);
        return mp[s];
    }
    
    void dfs(string s, const vector<string>& wordDict)
    {
        if(mp.find(s)!=mp.end()) return;
        
        vector<string> res;
        
        if(s.empty()) 
        {
            res.push_back(""); 
        }
        else
        {
            for(const auto& word:wordDict)
            {
                if(word.size()!=0 && s.find(word) == 0)
                {
                    dfs(s.substr(word.size()), wordDict);
                    for(const auto& str: mp[s.substr(word.size())])
                    {
                        if(str.empty())
                            res.push_back(word);
                        else
                            res.push_back(word+" "+str);
                    }
                }
            }   
        }
        mp[s] = res;
    }
    
};