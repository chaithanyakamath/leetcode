class Solution {
public:
int n;
vector<vector<int>> dp;
    int solve(vector<int>& satisfaction, int i, int time){
        if(i == n)  return 0;
        if(dp[i][time] != -1)   return dp[i][time];

        int take = (time * satisfaction[i]) + solve(satisfaction, i+1, time+1);
        int skip = solve(satisfaction, i+1, time);

        return dp[i][time] = max(take, skip);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        dp.assign(n, vector<int>(n+1, -1));
        return solve(satisfaction, 0, 1);
    }
};