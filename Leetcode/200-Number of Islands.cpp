class Solution {
public:
    vector<vector<int>> root;
    vector<vector<int>> vis;
    
    vector<int> dx = {1,0,-1,0};
    vector<int> dy = {0,1,0,-1};
    
    int check(const vector<vector<char>>& grid, int x, int y)
    {
        return x>=0 && x<grid.size() && y>=0 && y<grid[0].size() && grid[x][y]=='1';
    }
    
    void bfs(const vector<vector<char>>& grid, int x, int y)
    {
        for(int i=0;i<4;i++)
        {
            int cx = x+dx[i], cy = y+dy[i];
            if(check(grid, cx, cy) && !vis[cx][cy] )
            {
                vis[cx][cy] = 1;
                bfs(grid, cx, cy);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0 || grid[0].size()==0) return 0;
        vis = vector<vector<int>>(grid.size(), vector<int>(grid[0].size(), 0));
        int cnt = 0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(!vis[i][j] && grid[i][j]=='1')
                {
                    cnt++;
                    vis[i][j] = 1;
                    bfs(grid, i,j);
                }
            }
        }
        return cnt;
    }
};