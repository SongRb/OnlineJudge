class Solution {
public:
    vector<vector<int>> dig;
    vector<vector<int>> row;
    vector<vector<int>> col;
    
    vector<char> num {'0','1','2','3','4','5','6','7','8','9'};
    
    vector<vector<char>> result;
    
    bool found = false;
    
    void search(vector<vector<char>>& board, int depth)
    {
		if (depth == 81)
		{
			result = board;
			found = true;
			// for(int i=0;i<9;i++)
			// {
			// for(int j=0;j<9;j++)
			// {
			// cout<<board[i][j]<<" ";
			// }
			// cout<<endl;
			// }
			// cout << "found" << endl;
		}
		if (found) return;
		int i = depth % 9, j = depth / 9;
		if (board[i][j] == '.')
		{
            // cout<<depth<<endl;
			auto idx = 3 * (i / 3) + j / 3;
			for (int val = 1; val <= 9; val++)
			{
				if (!row[i][val] && !col[j][val] && !dig[idx][val])
				{
					//for (int k = 0; k<depth; k++) cout << " ";
					//cout << i << " " << j << " ";
					//cout << board[i][j] << "->" << num[val] << endl;
					row[i][val] = 1;
					col[j][val] = 1;
					dig[idx][val] = 1;
					board[i][j] = num[val];
					search(board, depth + 1);
					row[i][val] = 0;
					col[j][val] = 0;
					dig[idx][val] = 0;
					board[i][j] = '.';
				}
			}
		}
		else
		{
			search(board, depth + 1);
		}
    }
    
    
    void solveSudoku(vector<vector<char>>& board) {
        dig.insert(dig.end(),9, vector<int>(10,0));
        row.insert(row.end(),9, vector<int>(10,0));
        col.insert(col.end(),9, vector<int>(10,0));
        int count = 81;
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if (board[i][j] != '.')
				{
                    auto val = board[i][j] - '0';
                    auto idx = 3 * (i / 3) + j / 3;
                    row[i][val] = 1;
                    col[j][val] = 1;
                    dig[idx][val] = 1;
                    count--;
                }
            }
        }
        search(board, 0);
        // for(int k=3;k<=count+1;k++)
        // {
        //     cout<<k<<endl;
        //     search(board,0,k);
        //     if(found) board = result;
        // }
        board = result;
    }
};