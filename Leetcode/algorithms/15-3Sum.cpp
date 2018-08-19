class Solution {
public:
    int findMatch(const vector<int>& nums, int start, int end, int value)
    {
        if(value < nums[start]) return -1;
        if(value > nums[end]) return -1;
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
                return pivot;
            }
        }
        return -1;
    }
    
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        int length = nums.size();
        vector<vector<int>> result;
        unordered_map<int, unordered_map<int, int>> tmpResult;
        
        sort(nums.begin(),nums.end());
        
         
        for(int i=0;i<length-2;i++)
        {
            int sum = nums[i];
            for(int j=i+1;j<length-1;j++)
            {
                sum+=nums[j];

                if ( sum>0 ||   !(tmpResult.find(nums[i])!=tmpResult.end() && tmpResult[nums[i]].find(nums[j])!=tmpResult[nums[i]].end()))
                {
                    int candidate = 0 - sum;
                    int k = findMatch(nums,j+1,length-1,candidate);
                    if(k!=-1) 
                    {
                        // cout<<"Found "<<candidate<<" "<<k<<endl;
                        tmpResult[nums[i]][nums[j]] = nums[k];
                        // cout<<"Update: "<<nums[i]<<" "<<nums[j]<<" "<<tmpResult[nums[i]][nums[j]]<<endl;
                    }
                }
                sum-=nums[j];
            }
        }
        for(const auto& iter_i:tmpResult)
        {
            for(const auto& iter_j:iter_i.second)
            {
                result.push_back(vector<int>({iter_i.first,iter_j.first,iter_j.second}));
            }
        }
        return result;
    }
};