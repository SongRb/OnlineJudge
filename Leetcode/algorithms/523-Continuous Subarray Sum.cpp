class Solution {
public:
    bool checkCandidate(int num1, int k)
    {
        return (k!=0 && num1%k==0) || (k==0 && num1==0);
    }
    
    
    bool checkSubarraySum(vector<int>& nums, int k) {
        int length = nums.size();
        int* acc = new int[length];
        for(int i=0;i<length;i++)
        {
            if(i==0) acc[i] = nums[i];
            else acc[i] = acc[i-1]+nums[i];
            if( i!=0 && checkCandidate(acc[i],k) ) return true;
        }
        
        // upper bound
        for(int i=0;i<length;i++)
        {
            for(int j=0;j<i;j++)
            {
                if( i-j>1 && checkCandidate(acc[i]-acc[j],k) ) return true;
            }
        }
        return false;
    }
};