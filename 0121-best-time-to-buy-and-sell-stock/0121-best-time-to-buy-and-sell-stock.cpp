class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int minm=INT_MAX;

        for(int i=0;i<prices.size();i++)
        {   
            minm=min(minm,prices[i]);
    
            profit=max(profit,prices[i]-minm);
        }
        return profit;
    }
};