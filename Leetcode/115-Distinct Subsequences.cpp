class Solution {
public:
    vector<vector<int>> dp;
    int numDistinct(string s, string t) {
        if(t.size()==0) return 1;
        dp = vector<vector<int>>(s.size()+1, vector<int>(t.size()+1));
        for(int i=0;i<s.size();i++)
        {
            dp[i][0] = s[i]==t[0] ? 1:0;
        }
        
        for(int i=1;i<s.size();i++)
        {
            for(int j=1;j<t.size() && j<=i;j++)
            {
                if(s[i]==t[j])
                {
                    for(int k=0;k<i;k++)
                    {
                        dp[i][j] += dp[k][j-1];    
                    }   
                }
            }
        }
        
        int result = 0;
        for(int i=t.size()-1;i<s.size();i++)
        {
            result+=dp[i][t.size()-1];
        }
        
        return result;
    }
};