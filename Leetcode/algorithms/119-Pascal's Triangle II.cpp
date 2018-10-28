class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> result(2);
        int idx = 0;
        result[idx].push_back(1);
        for(int i=1;i<=rowIndex;i++)
        {
            for(int j=0;j<=i; j++)
            {
                if(j==0 || j==i) result[1-idx].push_back(1);
                else result[1-idx].push_back(result[idx][j-1] + result[idx][j]);
            }
            result[idx].erase(result[idx].begin(), result[idx].end());
            idx = 1-idx;
        }
        return result[idx];
    }
};