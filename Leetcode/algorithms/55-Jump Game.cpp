static string x =[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return "";
}();

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int length = nums.size();
        if(length<2) return true;
        vector<int> stpHead(length);
        for(int i=0;i<length;i++)
        {
            stpHead[i] = i+nums[i];
        }
        int cnt=1;
        int prev =0, next=stpHead[0];
        while(next<length-1)
        {
            int maxRange = -1;
            int maxIndex = -1;
            for(int i=prev+1;i<=next;i++)
            {
                if(maxRange<stpHead[i])
                {
                    maxRange = stpHead[i];
                    maxIndex = i;
                }
            }
            prev = maxIndex;
            next = stpHead[prev];
            if(next<length-1 && prev==next) return false;
        }
        return true;    
    }
};