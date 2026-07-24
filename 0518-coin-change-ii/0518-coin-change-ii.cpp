class Solution {
public:
int n;
vector<vector<int>> dp;
    int solve(vector<int>& coins, int i, int amt){
        if(amt == 0)    return 1;
        if(i == 0)  return (amt % coins[0] == 0);

        if(dp[i][amt] != -1)    return dp[i][amt];
        int take = 0;
        if(coins[i] <= amt) take = solve(coins, i, amt-coins[i]);
        int skip = solve(coins, i-1, amt);

        return dp[i][amt] = take + skip;
    }
    int change(int amount, vector<int>& coins) {
        n = coins.size();
        dp.assign(n+1, vector<int>(amount+1, -1));
        return solve(coins, n-1, amount);
    }
};