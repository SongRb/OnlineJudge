class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result(1,0);
        for(int i=0;i<n;i++)
        {
            int index = result.size()-1;
            while(index>=0)
            {
                int t = result[index];
                result.push_back(t+(1<<i));
                index--;
            }
        }
        return result;
    }
};