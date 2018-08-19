static const auto io_speed_up = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int trap(vector<int>& height) {
        int length = height.size();
        if(length<=2) return 0;
        int result = 0, i=0;
        // cout<<result<<endl;
        while(i<length-1)
        {
            int j=i+1, prev = i+1;
            if(height[i]>height[i+1]) 
            {
                while(j<length && height[j]<height[i]) 
                {
                    j++;
                    if(j<length && height[j]>height[prev]) prev = j;
                }
                if(prev!=i+1)
                {
                    int threshold = min(height[prev], height[i]);
                    // cout<<"Threshold: "<<threshold<<endl;
                    // cout<<i<<" "<<prev<<endl;
                    for(int k=i+1;k<prev;k++)
                    {
                        result+=threshold-height[k];
                        // cout<<threshold-height[k]<<endl;
                    } 
                }
            }
            i = prev;   
        }
        // cout<<result<<endl<<endl;
        return result;
    }
};