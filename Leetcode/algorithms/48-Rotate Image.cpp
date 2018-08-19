class Solution {
public:
    int getEle(const vector<vector<int>>& matrix, int i, int index)
    {
        int length = matrix.size();
        int width = length-2*i;
        int totalLength = width*4-4;
        
        
        int x = index/(width-1);
        int y = index%(width-1);
        if(x==0) return matrix[i][i+y];
        else if(x==1) return matrix[i+y][i+width-1];
        else if(x==2) return matrix[i+width-1][i+width-1-y];
        else return matrix[i+width-1-y][i];
    }
    
    void setEle(vector<vector<int>>& matrix, int i, int index, int val)
    {
        int length = matrix.size();
        int width = length-2*i;
        // cout<<i<<" "<<width<<endl;
        int totalLength = width*4-4;
        int x = index/(width-1);
        int y = index%(width-1);
        if(x==0) matrix[i][i+y]=val;
        else if(x==1) matrix[i+y][i+width-1]=val;
        else if(x==2) matrix[i+width-1][i+width-1-y]=val;
        else matrix[i+width-1-y][i]=val;
    }
    
    
    void rotate(vector<vector<int>>& matrix) {
        int length = matrix.size();
        for(int i=0;i<length-1-i;i++)
        {
            int width = length-2*i;
            int totalLength = width*4-4;
            vector<int> tmp;
            for(int idx=totalLength-width+1;idx<totalLength;idx++)
            {
                tmp.push_back(getEle(matrix,i,idx));
            }
            for(int idx=totalLength-width;idx>=0;idx--)
            {
                // cout<<getEle(matrix,i,idx)<<" ";
                setEle(matrix,i,idx+width-1,getEle(matrix,i,idx));
                // cout<<getEle(matrix,i,idx+width-1)<<endl;
            }
            for(int idx=0;idx<width-1;idx++)
            {
                setEle(matrix,i,idx,tmp[idx]);
                // cout<<getEle(matrix,i,idx)<<" ";
            }
        }
    }
};