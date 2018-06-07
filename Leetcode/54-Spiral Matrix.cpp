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
    
    
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int i=0, j=0;
        vector<int> result;
        if(matrix.size()==0) return result;
        int totalLength = matrix.size() * matrix[0].size();
        bool changed = false;
        int right = matrix[0].size();
        int left = -1;
        int up = matrix.size();
        int low = 0;
        while(true)
        {
            while(j<right) 
            {
                result.push_back(matrix[i][j]);        
                // cout<<matrix[i][j]<<endl;
                changed = true; 
                j++;
            }
            j--;
            i++;
            right--;
            if(result.size()==totalLength) break;
            
            while(i<up) 
            {
                result.push_back(matrix[i][j]);        
                // cout<<matrix[i][j]<<endl;
                changed = true;
                i++;
            }
            i--;
            j--;
            up--;
            if(result.size()==totalLength) break;
            
            while(j>left) 
            {
                result.push_back(matrix[i][j]);        
                // cout<<matrix[i][j]<<endl;
                changed = true;
                j--;
            }
            j++;
            i--;
            left++;
            if(result.size()==totalLength) break;
            
            while(i>low)
            {
                result.push_back(matrix[i][j]);        
                // cout<<matrix[i][j]<<endl;
                changed = true;
                i--;
            }
            i++;
            j++;
            low++;
            if(result.size()==totalLength) break;
            
            if(!changed) break;
            changed = false;
        }
        return result;
    }
};