class Solution {
public:
    int n;
    vector<int> dp; // declare
    int solve(int ptr, vector<int>& cost){
        if(ptr >= cost.size())  return 0;
        if(dp[ptr] != -1)   return dp[ptr]; // check

        int a = cost[ptr] + solve(ptr+1,cost);
        int b = cost[ptr] + solve(ptr+2,cost);

        return dp[ptr] = min(a,b); // store
    }
    int minCostClimbingStairs(vector<int>& cost) {
        n = cost.size();
        dp.assign(n+1, -1); // initialize
        return min(solve(0,cost), solve(1,cost));
    }
};