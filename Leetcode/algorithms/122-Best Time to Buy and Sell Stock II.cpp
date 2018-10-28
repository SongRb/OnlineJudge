class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        if(prices.size()>1) 
        {
            for(int i=0;i<prices.size()-1;i++) result+=max(0, prices[i+1] - prices[i]);
        }
        return result;
    }
};