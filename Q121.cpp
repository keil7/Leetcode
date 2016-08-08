class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
        int buyPrice = prices[0];
        int sellPrice = 0;
        int profit = 0;
        for(int i=1;i<prices.size();++i) {
            if(prices[i]<buyPrice) {
                if(sellPrice!=0) {//new estiamation period
                    if(profit<sellPrice-buyPrice)
                        profit = sellPrice-buyPrice;
                    sellPrice = 0;
                }
                buyPrice = prices[i];
            }
            else if(prices[i]>sellPrice)
                sellPrice = prices[i];
        }
        if(sellPrice!=0&&profit<sellPrice-buyPrice)
            profit = sellPrice-buyPrice;
            
        return profit;
    }
};
