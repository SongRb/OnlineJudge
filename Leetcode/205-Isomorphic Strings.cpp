class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()) return false;
        else
        {
            map<char, char> mp;
            set<char> vis;
            for(int i=0;i<s.size();i++)
            {
                if(mp.find(s[i])==mp.end())
                {
                    if(vis.find(t[i])==vis.end())
                    {
                        mp[s[i]] = t[i];
                        vis.insert(t[i]);   
                    }
                    else return false;
                }
                else if(mp[s[i]]!=t[i])
                {
                    return false;
                }
            }
            return true;
        }
    }
};