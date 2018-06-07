static int some = []()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int binary_search(const vector<int>& nums, int low, int high, int target)
    {

        while(low<=high)
        {
            int pivot = (low+high)/2;
            if(nums[pivot] == target)
            {
                return pivot;
            }
            else if(nums[pivot]>target)
            {
                high = pivot-1;
            }
            else
            {
                low = pivot+1;
            }
        }
        return -1;
    }
    
    int binary_search(const vector<int>& nums, int low, int high)
    {
        // 4 5 6 7 0 1 2
        // 0 6 3
        // 3 6 4
        // 3 4 3
        // return index of first increasing idx

        while(low<high)
        {
            int pivot = (low+high)/2;
            // cout<<low<<" "<<high<<endl;
            if(nums[pivot]>nums[low])
            {
                low = pivot;
            }
            else
            {
                high = pivot;
            }
        }
        return low;
    }
    
    int search(vector<int>& nums, int target) {
        int length = nums.size();
        if(length==0) return -1;
        int pivot = binary_search(nums, 0,length-1);
        // cout<<pivot<<endl;
        int res1 = binary_search(nums, 0,pivot,target);
        // cout<<res1<<endl;
        int res2 = binary_search(nums, pivot+1,length-1,target);
        // cout<<res2<<endl;
        if(res1 == -1) return res2;
        else return res1;
        // case 1: target > nums[0], target in prev segement
        
        // case 2: target < nums[length-1], target in later segement
        

    }
};