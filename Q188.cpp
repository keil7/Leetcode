class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(k<1||prices.size()<2)
            return 0;
        //simple case, max. profit in omptimal for this stock
        if(k>=(prices.size()+1)/2) {
            int maxProfit = 0;
            for(int i=1;i<prices.size();++i)
                maxProfit += max(prices[i]-prices[i-1],0);
                
            return maxProfit;
        } 
            
        vector<int> minPrice(k,INT_MAX);
        vector<int> maxProfit(k,0);
        
        for(auto curPrice : prices) {
                minPrice[0] = min(minPrice[0],curPrice);
                maxProfit[0] = max(maxProfit[0],curPrice-minPrice[0]);
            for(int i=1;i<k;++i) {
                minPrice[i] = min(minPrice[i],curPrice-maxProfit[i-1]);
                maxProfit[i] = max(maxProfit[i],curPrice-minPrice[i]);
            }
        }
        return maxProfit[k-1];
    }
};
