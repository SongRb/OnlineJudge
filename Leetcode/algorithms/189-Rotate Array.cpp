class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int cnt = 0;
        if(nums.size()==0) return;
        if(k==0) return;
        k = k%nums.size();
        cout<<k<<endl;
        vector<int> dummy(k,0);
        for(int i=0;i<k;i++)
        {
            dummy[i] = nums[nums.size()-k+i];
        }
        for(int i=nums.size()-k-1;i>=0;i--)
        {
            nums[i+k] = nums[i];
        }
        for(int i=0;i<k;i++)
        {
            nums[i] = dummy[i];
        }
    }
};