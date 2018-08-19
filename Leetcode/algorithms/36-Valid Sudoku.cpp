class Solution {
public:
    
    vector<vector<int>> dig;
    vector<vector<int>> row;
    vector<vector<int>> col;
    
    bool isValidSudoku(vector<vector<char>>& board) {
        dig.insert(dig.end(),9, vector<int>(10,0));
        row.insert(row.end(),9, vector<int>(10,0));
        col.insert(col.end(),9, vector<int>(10,0));
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if (board[i][j] != '.')
				{
                    auto val = board[i][j] - '0';
                    auto idx = 3 * (i / 3) + j / 3;
                    if(row[i][val]==1) return false;
                    if(col[j][val]==1) return false;
                    if(dig[idx][val]==1) return false;
                    row[i][val]=1;
                    col[j][val]=1;
                    dig[idx][val]=1;
                }
            }
        }
        return true;
    }
};