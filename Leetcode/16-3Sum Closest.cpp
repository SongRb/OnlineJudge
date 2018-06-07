class Solution {
public:
    int findCloset(const vector<int>& nums, int start, int end, int value)
    {
        if(value < nums[start]) return nums[start];
        if(value > nums[end]) return nums[end];
        int low = 0, high = end;
        while(low<=high)
        {
            int pivot = (low+high)/2;
            if(value<nums[pivot])
            {
                high = pivot-1;
            }
            else if(value>nums[pivot])
            {
                low = pivot+1;
            }
            else
            {
                return nums[pivot];
            }
        }
        return abs(value-nums[low]) < abs(nums[high]-value) ? nums[low]:nums[high];
    }
    int threeSumClosest(vector<int>& nums, int target) {
        int length = nums.size();
        int result = 1000000;
        
        sort(nums.begin(),nums.end());
         
        for(int i=0;i<length-2;i++)
        {
            int sum = nums[i];
            for(int j=i+1;j<length-1;j++)
            {
                sum+=nums[j];
                int candidate = target - sum;
                int searched = findCloset(nums,j+1,length-1,candidate);
                if(searched==candidate) return target;
                else
                {
                    sum+=searched;
                    if(abs(sum-target)<abs(result-target))
                    {
                        // cout<<i<<" "<<j<<endl;
                        // cout<<searched<<" "<<sum<<endl;
                        result = sum;
                    }
                    sum-=searched;
                }
                sum-=nums[j];
            }
        }
        return result;
    }
};