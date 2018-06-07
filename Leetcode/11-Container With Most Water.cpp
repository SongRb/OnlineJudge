class Solution {
public:
    int maxArea(vector<int>& height) {
        int result = -1;
        int length = height.size();
        if(length<2) return 0;
        int left = 0, right = length-1;
        while(left<right)
        {
            result = max(result, min(height[left],height[right]) * (right - left));
            if(height[left] < height[right]) left++;
            else right--;
        }
        return result;
    }
};