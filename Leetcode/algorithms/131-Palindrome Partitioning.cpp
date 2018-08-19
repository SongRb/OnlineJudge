class Solution {
public:
    bool isPali(const string& s)
    {
        for(int i=0;i<s.size() && i<s.size()-i-1;i++)
        {
            if(s[i]!=s[s.size()-i-1]) return false;
        }
        return true;
    }
    
    vector<vector<string>> result;
    
    void partition(string s, int index, vector<string>& vec)
    {
        if(index<s.size())
        {
            for(int i=index;i<s.size();i++)
            {
                auto str = s.substr(index, i-index+1);
                if(isPali(str))
                {
                    vec.push_back(str);
                    partition(s, i+1, vec);
                    vec.pop_back();
                }
            }            
        }
        else
        {
            result.push_back(vec);
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> vec;
        partition(s, 0, vec);
        return result;
    }
};