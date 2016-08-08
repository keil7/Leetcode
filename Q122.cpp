class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
        int profit = 0;
        int totalProfit = 0;
        int buyPrice = INT_MAX;
        
        for(int i=0;i<prices.size();++i) {
            buyPrice = min(buyPrice,prices[i]);
            if(profit>prices[i]-buyPrice) {
                totalProfit += profit;
                buyPrice = prices[i];
                profit = 0;
            }
            else
                profit = prices[i]-buyPrice;
        }
        
        totalProfit += profit;
        return totalProfit;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
        
        int totalProfit = 0;
       
        for(int i=1;i<prices.size();++i) {
           totalProfit += max(prices[i]-prices[i-1],0);
        }
        
        return totalProfit;
    }
};
