class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int i=0, j=0;
        int totalLength = n * n;
        vector<vector<int>> matrix(n, vector<int>(n));
        if(n==1)
        {
            matrix[0][0]=1;
        }
        else if(n>1)
        {
            int val = 1;
            int right = n, left = -1, up = n, low = 0;
            while(true)
            {
                // cout<<val<<endl;
                while(j<right) 
                {
                    matrix[i][j] = val++;     
                    j++;
                }
                j--;
                i++;
                right--;
                if(val>totalLength) break;

                while(i<up) 
                {
                    matrix[i][j] = val++;          
                    i++;
                }
                i--;
                j--;
                up--;
                if(val>totalLength) break;

                while(j>left) 
                {
                    matrix[i][j] = val++;        
                    j--;
                }
                j++;
                i--;
                left++;
                if(val>totalLength) break;

                while(i>low)
                {
                    matrix[i][j] = val++;       
                    i--;
                }
                i++;
                j++;
                low++;
                if(val>totalLength) break;
            }   
        }
        return matrix;
    }
};