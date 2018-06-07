class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int length = nums.size();
        if(k>length || length==0) return -1;
        for(int i=0;i<length;i++)
        {
            if(i<k)
            {
                pq.push(nums[i]);   
                // cout<<"Pushed"<<endl;
            }
            else
            {
                if(pq.top()<nums[i])
                {
                    // cout<<"Poped: "<<pq.top()<<" for "<<nums[i]<<endl;
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
        }
        int result = pq.top();
        return result;
    }
};