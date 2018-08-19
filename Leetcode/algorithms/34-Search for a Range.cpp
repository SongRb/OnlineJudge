class Solution {
public:
    int findLo(const vector<int> nums, int target)
    {
                // cout<<"Find low"<<endl;
        int low = 0, high = nums.size()-1;
        while(low<high)
        {
            // cout<<low<<" "<<high<<endl;
            int pivot = (low+high)/2;
            if(nums[pivot]>target) high = pivot-1;
            else if(nums[pivot]<target) low=pivot+1;
            else
            {
                high=pivot;
            }
            
            if(low+1==high)
            {
                if(nums[low]==target) return low;
                if(nums[high]==target) return high;
                return -1;
            }
        }
        if(nums[low]==target) return low;
        else return -1;
    }
    
    
    int findUp(const vector<int> nums, int target)
    {
        // cout<<"Find up"<<endl;
        int low = 0, high = nums.size()-1;
        while(low<high)
        {
                        // cout<<low<<" "<<high<<endl;
            int pivot = (low+high)/2;
            if(nums[pivot]>target) high = pivot-1;
            else if(nums[pivot]<target) low=pivot+1;
            else
            {
                low=pivot;
            }
            if(low+1==high)
            {
                if(nums[high]==target) return high;
                if(nums[low]==target) return low;
                return -1;
            }
        }
        if(nums[low]==target) return low;
        else return -1;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        if(nums.size()==0)
        {
            result.push_back(-1);
            result.push_back(-1);
        }
        else
        {
            result.push_back(findLo(nums,target));
            result.push_back(findUp(nums,target));
        }
        return result;
    }
};