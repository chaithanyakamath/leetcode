class Solution {
public:
    int n,m;
    vector<vector<int>> dp; // declare
    vector<vector<bool>> visited;
    int solve(vector<vector<int>>& matrix, int row, int col){
        if(col< 0 || col>= m) return INT_MAX;
        if(row == n-1)  return matrix[row][col];

        if(visited[row][col])  return dp[row][col]; // check

        visited[row][col] = true;
        int a = solve(matrix, row+1, col+1);
        int b = solve(matrix, row+1, col);
        int c = solve(matrix, row+1, col-1);

        int best = min({a,b,c});
        return dp[row][col] = matrix[row][col] + best; // store
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();

        int ans = INT_MAX;
        dp.assign(n, vector<int>(m));
        visited.assign(n, vector<bool>(m, false));
        for(int col=0; col<m; col++)    ans = min(ans, solve(matrix, 0, col));
        return ans;
    }
};