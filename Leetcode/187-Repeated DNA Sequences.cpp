class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> vec;
        map<string, int> mp;
        if(s.size()<=10) return vec;
        for(int i=0;i<s.size()-10+1;i++)
        {
            auto str = s.substr(i,10);
            mp[str]++;
        }
        for(map<string, int>::iterator it = mp.begin(); it!=mp.end(); it++)
        {
            if(it->second>1) vec.push_back(it->first);
        }
        return vec;
    }
};