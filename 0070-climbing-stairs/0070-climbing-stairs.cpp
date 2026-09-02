class Solution {
public:
    vector<int> dp; // declare
    int solve(int n){
        if(n <= 2)  return n;
        if(dp[n] != -1) return dp[n]; // if calculated
        return dp[n] = solve(n-1) + solve(n-2); //store
    }
    int climbStairs(int n) {
        dp.assign(n+1, -1); // initiaize
        return solve(n);
    }
};