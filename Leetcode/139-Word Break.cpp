class Solution {
public:
    set<string> dict;
    int maxWordLength = 0;
    int minWordLength = 10000;
    bool search(string word)
    {
        if(dict.find(word)!=dict.end()) return true;
        cout<<"Dealing with "<<word<<endl;
        int length = word.size();
        for(int i=maxWordLength;i>=1;i--)
        {
            bool result;
            cout<<"Looking for "<<word.substr(0,i)<<endl;
            if(dict.find(word.substr(0,i)) != dict.end()) 
            {
                result = search(word.substr(i));
            }
            if(result) return result;
        }
        return false;
    }
    
    
    
    bool wordBreak(string s, vector<string>& wordDict) {
        dict.insert(wordDict.begin(),wordDict.end());
        int length = s.size();
        vector<int> dp(length,0);
        for(const auto& word:wordDict) 
        {   
            maxWordLength = max(maxWordLength,(int)word.size());
            minWordLength = min(minWordLength,(int)word.size());
        }
        bool first = true;
        for(int i=0;i<length;i++)
        {
            for(int j=-1; j<i; j++)
            {
                // cout<<s.substr(j+1,i-j)<<endl;
                // From j+1 to i, length should be i-j
                if(i-j>=minWordLength && i-j <=maxWordLength && dict.find(s.substr(j+1,i-j))!=dict.end())
                {
                    // cout<<"Found"<<endl;
                    if(j==-1) dp[i]=1;
                    else if(dp[j]==1) 
                    {
                        dp[i] = 1;
                        break;
                    }
                }
            }
            cout<<dp[i]<<endl;
        }
        return dp[length-1];
    }
};