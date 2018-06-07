class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;
        int carry = 1;
        int length = digits.size();
        for(int i=length-1;i>=0;i--)
        {
                        // cout<<digits[i]<<" "<<carry<<endl;
            int tmp = (digits[i]+carry)%10;
            carry = (digits[i]+carry) / 10;
            digits[i] = tmp;
        }
        if(carry==1)
        {
            result.push_back(1);
        }
        result.insert(result.end(), digits.begin(), digits.end());
        return result;
    }
};