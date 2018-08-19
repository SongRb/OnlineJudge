class Solution {
public:
    
    int search(vector<int>& arr, int target, int upper)
    {
        int left = 0, right = upper;
        while(left<right)
        {
            int pivot = (right+left+1)/2;
            if(arr[pivot]>=target)
            {
                right = pivot;
            }
            else if(arr[pivot]<target)
            {
                left = pivot;
            }
            if(left+1==right)
            {
                return right;
            }
        }
        return right;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int h = matrix.size();
        if(h==0) return false;
        int w = matrix[0].size();
        if(w==0) return false;
        if(matrix[0][0]>target || matrix[h-1][w-1]<target) return false;
        // int left=0, right = h-1;
        // while(left<=right)
        // {
        //     int pivot = (left+right)/2;
        //     // cout<<matrix[pivot/h][pivot%h]<<endl;
        //     if(matrix[pivot/h][pivot%h]>target)
        //     {
        //         right = pivot-1;
        //     }
        //     else if(matrix[pivot/h][pivot%h]<target)
        //     {
        //         left = pivot+1;
        //     }
        //     else {return true;}
        // }
        
        
        
        int left = 0, right = h*w-1;
        while(left<=right)
        {
            // cout<<left<<" "<<right<<endl;
            int pivot = (left+right)/2;
            // cout<<matrix[pivot/w][pivot%w]<<endl;
            if(matrix[pivot/w][pivot%w]>target)
            {
                right = pivot-1;
            }
            else if(matrix[pivot/w][pivot%w]<target)
            {
                left = pivot+1;
            }
            else {
                // cout<<pivot<<endl;
                return true;}
        }
        return false;
        
    
        // int upper = w-1;
        // for(int i=0;i<h;i++)
        // {
        //     if(matrix[i][0]>target) return false;
        //     if(upper<2)
        //     {
        //         for(int j=0;j<=upper;j++) 
        //         {   
        //             if(matrix[i][j]==target) return true;
        //             if(matrix[i][j]>target)
        //             { 
        //                 upper = j; break;
        //             }
        //         }
        //     }
        //     else
        //     {
        //         auto idx = search(matrix[i], target, upper);
        //         cout<<idx<<endl;
        //         if(matrix[i][idx]==target) return true;
        //         else upper = idx;
        //     }
        // }
        // return false;
    }
};