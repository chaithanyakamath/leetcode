class Solution {
public:
int n;
vector<int> dp;
    int solve(vector<int>& days, vector<int>& costs, int i){
        if(i == n)  return 0;
        if(dp[i] != -1) return dp[i];

        int j = i;
        while(j<n && days[j] < days[i] + 1) j++;
        int a = costs[0] + solve(days, costs, j);

        j = i;
        while(j < n && days[j] < days[i]+7) j++;
        int b = costs[1] + solve(days, costs, j);

        j=i;
        while(j < n && days[j] < days[i]+30)    j++;
        int c = costs[2] + solve(days, costs, j);

        return dp[i] = min({a,b,c});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        n = days.size();
        dp.assign(n+1, -1);
        return solve(days,costs,0);
    }
};