class Solution {
public:
    vector<vector<bool>> isVisited;
    int height, width;
    vector<int> dx = {1,0,-1,0};
    vector<int> dy = {0,1,0,-1};
    bool check(int x, int y, const vector<vector<char>>& board)
    {
        return x>=0 && x<height && y>=0 && y<width && board[x][y]=='O';
    }
    
    void bfs(int x, int y, const vector<vector<char>>& board)
    {
        if(board[x][y]=='O')
        {
            isVisited[x][y]=true;
            for(int i=0;i<4;i++)
            {
                int cx = x+dx[i], cy = y+dy[i];
                if(check(cx,cy,board) && !isVisited[cx][cy]) {isVisited[cx][cy]=true;bfs(cx,cy, board);}
            }   
        }
    }
    
    void solve(vector<vector<char>>& board) {
        height = board.size();
        if(height==0) return;
        width = board[0].size();
        if(width==0) return;
        isVisited = vector<vector<bool>>(height, vector<bool>(width, false));
        for(int i=0;i<height;i++) bfs(i,0,board);
        for(int i=0;i<height;i++) bfs(i,width-1,board);
        for(int i=0;i<width;i++) bfs(0,i,board);
        for(int i=0;i<width;i++) bfs(height-1,i,board);
        
        for(int i=0;i<height;i++)
        {
            for(int j=0;j<width;j++)
            {
                if(board[i][j]=='O' && !isVisited[i][j]) board[i][j]='X';
            }
        }
    }
};