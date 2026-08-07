class Solution {
public:
int n, m;
vector<vector<int>> dp;
    int solve(vector<vector<int>>& piles, int i, int k){
        if(i == n || k == 0)  return 0;
        if(dp[i][k] != -1)  return dp[i][k];

        int skip = solve(piles, i+1, k);
        int take = 0, sum = 0, maxSum = 0;
        for(int j=0; j<min(k, (int)piles[i].size()); j++){
            sum += piles[i][j];
            take = max(take, sum + solve(piles, i+1, (k-(j+1))));
        }

        return dp[i][k] = max(take, skip);
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        n = piles.size();
        m = piles[0].size();
        dp.assign(n, vector<int>(k+1, -1));
        return solve(piles,0,k);
    }
};