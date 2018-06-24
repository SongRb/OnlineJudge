class Solution {
public:
    vector<int> dp;
    
    int f(int n)
    {
        if(n<1000 && dp[n]!=0) return dp[n];
        else
        {
            int result= 0;
            for(int i=0;i<n;i++)
            {
                result+=f(i)*f(n-i-1);
            }
            if(n<1000) dp[n] = result;
            return result;
        }
    }
    int numTrees(int n) {
        dp = vector<int>(1000,0);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        return f(n);
    }
};