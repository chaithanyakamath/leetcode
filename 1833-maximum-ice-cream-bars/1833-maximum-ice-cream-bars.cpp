class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int count = 0;

        int n = costs.size();
        for(int n : costs){
            if(coins >= n){
                count++;
                coins -= n;
            }
        }
        return count;
    }
};