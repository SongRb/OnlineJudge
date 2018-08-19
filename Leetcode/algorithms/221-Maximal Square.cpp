class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int length = matrix.size();
        if(length==0) return 0;
        int width = matrix[0].size();


        int best = -1;
        vector<vector<int>> score = vector<vector<int>>(length, vector<int>(width,0));
        for(int i=0;i<width;i++)
        {
            score[0][i] = matrix[0][i] - '0';
                                best = max(best, score[0][i]);
        }
        for(int i=0;i<length;i++)
        {
            score[i][0] = matrix[i][0] - '0';
                                best = max(best, score[i][0]);
        }
        for(int i=1;i<length;i++)
            for(int j=1;j<width;j++)
            {
                if(matrix[i][j]=='1')
                {
                    score[i][j] = min(score[i-1][j-1],min(score[i][j-1],score[i-1][j]))+1;
                    best = max(best, score[i][j]);
                }
            }
        return best*best;
    }
};