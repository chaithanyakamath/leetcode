class Solution {
public:
int n;
vector<vector<int>> dp;
    int solve(int i, vector<int>& stones, int target){
        if(i >= n || target == 0)  return 0;
        if(dp[i][target] != -1)  return dp[i][target];

        int skip = solve(i+1, stones, target);
        int take = 0;
        if(stones[i] <= target)  take = stones[i] + solve(i+1, stones, target-stones[i]);

        return dp[i][target] = max(take,skip);
    }
    int lastStoneWeightII(vector<int>& stones) {
        n = stones.size();
        int sum = 0;
        for(int n : stones) sum += n;
        int target = sum/2;
        dp.assign(n, vector<int>(target+1, -1));
        int ans = solve(0, stones, target); 
        return sum - 2*ans;
    }
};