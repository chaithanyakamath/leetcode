class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = prices[0]; //assume that we brought on first day
        int profit = 0;

        for(int i=1; i<n; i++){
            if(prices[i] < buy){ // price went down ==> buy it
                buy = prices[i];
            }
            else if(prices[i] - buy > profit){
                profit = prices[i] - buy;
            }
        } 
        return profit;
    }
};