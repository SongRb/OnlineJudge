class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2) return 0;
        else if(prices.size()==2) return max(0, prices[1]-prices[0]);
        else
        {
            int maxProfit = -1;
            int minPrice = 1000000000;
            map<int, int> maxPrice;
            for(const auto& num: prices) maxPrice[num]++;
            for(int i=0;i<prices.size()-1;i++)
            {
                minPrice = min(minPrice, prices[i]);
                maxPrice[prices[i]]--;
                if(maxPrice[prices[i]]==0) maxPrice.erase(maxPrice.find(prices[i]));
                maxProfit = max(maxProfit, maxPrice.rbegin()->first-minPrice);
            }
            return max(0, maxProfit);
        }
    }
};