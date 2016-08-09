class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
            
        vector<int> p1(prices.size(),0);
        vector<int> p2(p1);
        //DP solution;
        maxProfitOneTrans(prices,0,prices.size()-1,p1);
        maxProfitOneTrans(prices,prices.size()-1,0,p2);
        
        int totalProfit = 0;
        for(int i=0;i<=prices.size()-1;++i)
            totalProfit = max(totalProfit,p1[i]+p2[i]);
            
        return totalProfit;
    }
    
private:
    void maxProfitOneTrans(vector<int>& prices,const int begin,const int end,vector<int>& p ) {
        int profit = 0;
        if(begin<=end) {
            int buyPrice = INT_MAX;
            for(int i=begin;i<=end;++i) {
                buyPrice = min(buyPrice,prices[i]);
                profit = max(profit,prices[i]-buyPrice);
                p[i] = profit;
            }
        }
        else {
            int sellPrice = INT_MIN;
            for(int i=begin;i>=end;--i) {
                sellPrice = max(sellPrice,prices[i]);
                profit = max(profit,sellPrice-prices[i]);
                p[i] = profit;
            }
        }
    }
    
};
