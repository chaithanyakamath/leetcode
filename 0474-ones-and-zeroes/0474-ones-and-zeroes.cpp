class Solution {
public:
int len;
vector<vector<vector<int>>> dp;
    int solve(int i, vector<string>& strs, int m, int n){
        if(i >= len) return 0;
        if(dp[i][m][n] != -1)    return dp[i][m][n];

        int zCount = count(strs[i].begin(), strs[i].end(), '0');
        int oCount = strs[i].size() - zCount;

        if(m-zCount >= 0 && n-oCount >= 0){
            return dp[i][m][n] = max(1+solve(i+1, strs, m-zCount, n-oCount), solve(i+1, strs, m, n));
        }
        return dp[i][m][n] = solve(i+1, strs, m, n);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        len = strs.size();
        dp.assign(len, vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        return solve(0, strs, m, n);
    }
};