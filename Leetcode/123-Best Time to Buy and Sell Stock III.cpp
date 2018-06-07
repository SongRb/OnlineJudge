class Solution {
public:
    // Supposing that we denote i as first sell day.
    int maxProfit(vector<int>& prices) {
        int length = prices.size();
        if(length==0) return 0;
        int global[length][3] = {0};
        int local[length][3] = {0};
        for(int i=1;i<length;i++)
        {
            int diff = prices[i]-prices[i-1];
            for(int j=1;j<3;j++)
            {
                local[i][j] = max(local[i-1][j],global[i-1][j-1])+diff;
                global[i][j] = max(local[i][j],global[i-1][j]);
            }
        }
        return global[length-1][2];
    }
};