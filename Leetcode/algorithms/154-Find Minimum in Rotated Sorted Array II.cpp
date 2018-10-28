class Solution {
public:
    int findMin(vector<int>& nums, int start, int end)
    {
        // cout<<"New Stack!"<<endl;
        if(start!=end && nums[start]>=nums[end])
        {
            while(start<end)
            {
                int mid = (start+end)/2;
                // cout<<"Index: "<<start<<" "<<mid<<" "<<end<<endl;
                // cout<<"Value: "<<nums[start]<<" "<<nums[mid]<<" "<<nums[end]<<endl;
                if(nums[start]<nums[end]) return nums[start];
                if(nums[mid]>nums[start])
                {
                    start = mid+1;
                }
                else if(nums[mid]==nums[start])
                {
                    return min(findMin(nums, start, mid), findMin(nums, mid+1, end));
                }
                else
                {
                    end = mid;
                }   
            }
        }
        return nums[start];
    }
    
    
    int findMin(vector<int>& nums) {
        int start = 0, end = nums.size()-1;
        return findMin(nums, start, end);
    }
};