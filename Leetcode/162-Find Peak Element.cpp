class Solution {
public:    
    const long INTMIN = -2147483650;

    int findPeakElement(vector<int>& nums) {
        int left = -1;
        int right = nums.size();
        while(left<right)
        {
            // cout<<left<<" "<<right<<endl;
            int pivot = (left+right)/2;
            long leftValue = pivot-1==-1?INTMIN-1:(long)nums[pivot-1];
            long rightValue = pivot+1==nums.size()?INTMIN-1:(long)nums[pivot+1];
            long currentValue = (long)nums[pivot];
            

            if(leftValue<currentValue && currentValue<rightValue)
            {
                left = pivot+1;
            }
            else if(leftValue>currentValue && currentValue>rightValue)
            {
                right = pivot-1;
            }
            else if(leftValue>currentValue && currentValue<rightValue)
            {
                right = pivot-1;
            }
            else // leftValue<nums[pivot] && nums[pivot]>rightValue
            {
                return pivot;
            }
        }
        return left;
    }
};