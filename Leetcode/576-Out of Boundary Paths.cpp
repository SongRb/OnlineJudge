class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        vector<vector<vector<uint>>> arr(N+1,vector<vector<uint>>(m,vector<uint>(n,0)));
        for(int k=1;k<=N;k++)
        {
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    arr[k][i][j] = ((i==0?1:arr[k-1][i-1][j]) % 1000000007 + (j==0?1:arr[k-1][i][j-1]) % 1000000007 + (i==m-1?1:arr[k-1][i+1][j])% 1000000007 + (j==n-1?1:arr[k-1][i][j+1])% 1000000007) % 1000000007;
                }
            }
        }
        return arr[N][i][j];
    }
};