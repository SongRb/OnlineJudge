class Solution {
public:    
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        int maxArea = 0;
        int length = heights.size();
        for(int k=0;k<=length;k++)
        {
            int h = (k == length ? 0 : heights[k]);
            if(stk.empty() || heights[stk.top()]<=h)
            {
                stk.push(k);                  
            }
            else
            {
                int tp = stk.top();
                stk.pop();
                maxArea = max(maxArea,heights[tp]*(stk.empty()?k:k-1-stk.top()) );
                k--;
            } 
        }
        return maxArea;
    }
};