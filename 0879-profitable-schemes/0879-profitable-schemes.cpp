class Solution {
public:
int len;
const int MOD = 1000000007;
vector<vector<vector<int>>> dp;
    int solve(int i, int n, int minProfit, vector<int>& group, vector<int>& profit){
        if(i == len)   return minProfit <= 0;
        if(dp[i][n][minProfit] != -1)  return dp[i][n][minProfit];

        int skip = solve(i+1, n, minProfit, group, profit);
        int take = 0;
        if(n >= group[i]){
            take = solve(i+1, n-group[i], max(0,minProfit-profit[i]), group, profit);
        }
        return dp[i][n][minProfit] = (take + skip) % MOD;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        len = group.size();
        dp.assign(len, vector<vector<int>>(n+1, vector<int>(minProfit+1, -1)));

        int ans = solve(0, n, minProfit, group, profit);
        return ans;
    }
};