class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if(numRows<1) return result;
        result.emplace_back(1,1);
        for(int i=1; i<numRows; i++)
        {
            vector<int> curRow;
            for(int j=0; j<i+1; j++)
            {
                if(j==0 || j==i) curRow.push_back(1);
                else curRow.push_back(result[i-1][j-1]+result[i-1][j]);
            }
            result.push_back(curRow);
        }
        return result;
    }
};