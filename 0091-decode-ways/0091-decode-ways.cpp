class Solution {
public:
    int n;
    vector<int> dp;
    int solve(string s, int i){
        if(i >= n)  return 1;

        if(dp[i] != -1) return dp[i];

        if(s[i] == '0') return 0;
        int ways = solve(s, i+1);
        if(i+1 < n && (s[i]=='1' || s[i]=='2' && s[i+1] <= '6'))     ways += solve(s, i+2);

        return dp[i] = ways;
    }
    int numDecodings(string s) {
        n = s.size();
        dp.assign(n+1, -1);
        return solve(s,0);
    }
};