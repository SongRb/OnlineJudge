class Solution {
public:
    const int MAXINT = 100000000;
    
    int minCut(string s) {
        // dp[i] represents s[i..] min cut
        // isPali[i][j] represents s[i..j] is pali or not
        vector<int> dp(s.size()+1);
        vector<vector<int>> isPali(s.size()+1, vector<int>(s.size()+1));
        
        for(int i=s.size()-1;i>=0;i--)
        {
            dp[i] = MAXINT;
            for(int j=i;j<s.size();j++)
            {
                if(s[i]==s[j] && (j-i<=1 || isPali[i+1][j-1]==1 ))
                {
                    isPali[i][j] = 1;
                    dp[i] = min(dp[j+1]+1, dp[i]);
                }
            }
        }
        return dp[0] - 1;
    }
};