class Solution {
public:
    int n, m;
    vector<vector<int>> dp;
    int solve(vector<vector<int>>& obs, int i, int j){
        if(i>=n ||  j>=m || obs[i][j] == 1)    return 0;
        if(i == n-1 && j == m-1)    return 1;

        if(dp[i][j] != -1)  return dp[i][j];
        int right = solve(obs,i+1,j);
        int down = solve(obs,i,j+1);

        return dp[i][j] = right + down;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        n = obs.size();
        m = obs[0].size();

        dp.assign(n, vector<int>(m, -1));
        return solve(obs,0,0);
    }
};