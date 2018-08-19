class Solution {
public:
    int searchClosest(const vector<int>& arr, int target)
    {
        int left = 0, right = arr.size()-1;
        if(arr[left]>=target) return left;
        else if(arr[right]<=target) return right;
        while(left<=right)
        {
            int pivot = (left+right)/2;
            if(arr[pivot] < target) left = pivot+1;
            else if(arr[pivot] > target) right = pivot-1;
            else return pivot;
        }
        return abs(target - arr[left]) <= abs(arr[right]-target)?left:right;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int idx = searchClosest(arr, x);
        // k--;
        deque<int> dq;
        // dq.push_back(arr[idx]);
        int left = idx, right = idx+1;
        while(dq.size()<k)
        {
            while(dq.size()<k && left>=0 && (right>=arr.size() || x - arr[left] <= arr[right] - x))
            {
                dq.push_front(arr[left]);
                left--;
            }
            while(dq.size()<k && right<arr.size() && (left<0 || x - arr[left] > arr[right] - x))
            {
                dq.push_back(arr[right]);
                right++;
                
            }
        }
        vector<int> result(dq.begin(), dq.end());
        return result;
    }
};