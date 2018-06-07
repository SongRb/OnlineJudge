class Solution {
public:
    void sortColors(vector<int>& nums) {
        int length = nums.size();
        int one = 0, two = 0;
    
        for(int i=0;i<length;i++)
        {
            if(nums[i]==1) one++;
            else if(nums[i]==2) two++;
        }
        cout<<one<<" "<<two<<endl;
        for(int i=length-1;i>=0;i--)
        {
            if(two>0) {nums[i]=2;two--;}
            else if(one>0) {nums[i]=1;one--;}
            else
            {
                nums[i]=0;
            }
        }
    }
};