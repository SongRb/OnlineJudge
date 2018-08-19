class Solution {
public:
    void update(const string& s, const vector<int>& idx, int right, int left,int cnt,int clen, string& result, int& best)
    {
        int ilen = idx.size();
        // if(right<ilen)
        // {
        //     if(idx[right]-idx[left]<best)
        //     {
        //         result = s.substr(idx[left],idx[right]-idx[left]);
        //         best = idx[right] - idx[left];
        //         cout<<idx[right]<<" "<<idx[left]<<endl;
        //         cout<<"best: "<<best<<endl;
        //         cout<<result<<endl;
        //     }
        // }
        // else if(right==ilen && cnt==clen)
        // {
            if(cnt==clen && idx[right-1]+1-idx[left]<best)
            {
                result = s.substr(idx[left],idx[right-1]+1-idx[left]);
                best = idx[right-1]+1 - idx[left];
                // cout<<"best: "<<best<<endl;
                // cout<<result<<endl;
            }
        // }
    }
    
    
    string minWindow(string s, string t) {
        int slen = s.size();
        int tlen = t.size();
        int best = slen+2;
        if(slen==0) return s;
        if(tlen==0) return s.substr(0,1);
        
        unordered_map<char,int> mp2;
        for(const auto& ch: t)
        {
            mp2[ch]+=1;
        }
        
        vector<int> idx;
        for(int i=0;i<slen;i++)
        {
            if(mp2.find(s[i])!=mp2.end()) 
            {
                idx.push_back(i);
            }
        }
        
        unordered_map<char,int> mp;
        
        int ilen = idx.size();
        string result = "";
        // Init window
        // left indicates left bound?
        int left = 0, right = 0, cnt=0, clen=mp2.size();
        while(right<ilen)
        {
            while(right<ilen && cnt<clen)
            {
                mp[s[idx[right]]]++;
                if(mp[s[idx[right]]]==mp2[s[idx[right]]]) 
                {
                    cnt++;
                }
                right++;
                // cout<<"right: "<<right<<" "<<idx[right]<<endl;
            }
            update(s, idx, right, left,cnt,clen, result, best);

            while(cnt==clen)
            {
                mp[s[idx[left]]]--;
                if(mp[s[idx[left]]]==mp2[s[idx[left]]]-1) 
                {
                    cnt--;
                }
                left++;
                // cout<<"left: "<<idx[left]<<endl;
                if(cnt==clen) update(s, idx, right, left,cnt,clen, result, best);
            }
        }
        return result;
    }
};