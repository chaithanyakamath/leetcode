class Solution {
public:
int n;
vector<vector<int>> dp;
    int solve(vector<int>&coins, int i, int amount){
        if(amount == 0) return 0;
        if(i == 0){
            if(amount % coins[i] == 0)  return amount/coins[0];
            return  1e9;
        }

        if(dp[i][amount] != -1) return dp[i][amount];
        int take = 1e9;
        if(coins[i] <= amount)  take = 1 + solve(coins, i, amount - coins[i]);
        int skip = solve(coins, i-1, amount);

        return dp[i][amount] = min(take, skip);
    }
    int coinChange(vector<int>& coins, int amount) {
        n = coins.size();
        dp.assign(n+1, vector<int>(amount+1, -1));
        int ans =  solve(coins, n-1, amount);
        return (ans >= 1e9) ? -1 : ans;
    }
};