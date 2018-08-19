class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int lowerBound = 1000000;
        int length = nums.size();
        if(length==0) return 1;
        int minimum = 1;
        int i=0;
        bool isChanged = false;
        
        int delta = 1;
        while(true)
        {
            if(nums[i]>0)
            {
                if(minimum==nums[i])
                {
                    minimum = nums[i]+1;
                    cout<<nums[i]<<" "<<minimum<<endl;
                    nums[i] = -1;
                    isChanged = true;
                }
            }
            i+=delta;
            
            if(i==length)
            {
                if(isChanged)
                {
                    i=length-1;
                    delta = -1;
                    isChanged = false;
                }
                else return minimum;
            }
            else if(i==-1)
            {
                if(isChanged)
                {
                    i=0;
                    delta = 1;
                    isChanged = false;
                }
                else return minimum;
            }
        }
    }
};