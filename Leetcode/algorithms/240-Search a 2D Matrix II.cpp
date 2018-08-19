class Solution {
public:
    int upperBound(vector<int> a,int bound, int key){
        int s =0,e=bound;
        int ans = -1;

        while(s<=e){
            int mid = (s+e)/2;

            if(a[mid]==key){
                return mid;
            }
            else if(a[mid]>key){
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }

        return s;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int h = matrix.size();
        if(h==0) return false;
        int w = matrix[0].size();
        if(w==0) return false;
        if(matrix[0][0]>target || matrix[h-1][w-1]<target) return false;
        int bound = w-1;
        for(int i=0;i<h;i++)
        {
            if(matrix[i][0]>target) return false;
            auto idx = upperBound(matrix[i],bound, target);
            // cout<<idx<<endl;
            if(idx<w && matrix[i][idx]==target) return true;
            else bound = min(bound,idx);
        }
        return false;
    }
};