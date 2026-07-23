class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>& store, int i, int n){
        if(n == 0)  return 0;
        if(i == store.size())   return 1e9;

        if(dp[i][n] != -1) return dp[i][n];
        int take = INT_MAX;
        if(n >= store[i])   take = 1 + solve(store, i, n - store[i]);
        int skip = solve(store, i+1, n);

        return dp[i][n] = min(take, skip);
    }
    int numSquares(int n) {
        vector<int> store;
        for(int i=1; (i*i)<=n; i++){
            store.push_back(i*i);
        }
        int m = store.size();
        dp.assign(m+1, vector<int>(n+1, -1));
        return solve(store,0,n);
    }
};