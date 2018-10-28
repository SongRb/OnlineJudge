class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        int left=0, right=numbers.size()-1;
        while(left<right)
        {
            if(numbers[left]+numbers[right]>target) right--;
            else if(numbers[left]+numbers[right]<target) left++;
            else
            {
                result.push_back(left+1);
                result.push_back(right+1);
                break;
            }
        }
        return result;
    }
};