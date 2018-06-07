class Solution {
public:
    bool checkBound(int x, int y, int right, int down)
    {
        return x>=0 && y>=0 && x<=down && y<=right;    
    }
    
    void setZeroes(vector<vector<int>>& matrix) {
        int h = matrix.size();
        int w = matrix[0].size();
        vector<int> dx = {-1,1,0,0};
        vector<int> dy = {0,0,-1,1};
        vector<int> xx(h,0);
        vector<int> yy(w,0);
        if(h==0 || w==0) return;
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                if(matrix[i][j]==0)
                {
                    // if(xx[i]==0) for(int k=0;k<w;k++) matrix[i][k]=0;
                    xx[i]=1;
                    // if(yy[j]==0) for(int k=0;k<h;k++) matrix[k][j]=0;
                    yy[j]=1;
                    // for(int k=0;k<4;k++)
                    // {
                    //     if( (k==0 || k==1) && xx[x]==0 )
                    //     int x=i,y=j;
                    //     while(check(x, y, h-1, w-1))
                    //     {
                    //         matrix[x][y] = 0;
                    //         x+=dx[k];
                    //         y+=dy[k];
                    //     }
                    // }
                }
            }
        }
        for(int i=0;i<h;i++)
        {
            if(xx[i]==1)
            {
                for(int k=0;k<w;k++) matrix[i][k]=0;
            }
        }
        for(int i=0;i<w;i++)
        {
            if(yy[i]==1)
            {
                for(int k=0;k<h;k++) matrix[k][i]=0;
            }
        }
    }
};