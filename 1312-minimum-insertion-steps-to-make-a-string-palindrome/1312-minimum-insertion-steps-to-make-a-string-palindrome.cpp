class Solution {
public:
int n;
vector<vector<int>> dp;
    int solve(int l, int r, const string& s){
        if(l>=r)    return 0;
        if(dp[l][r] != -1)  return dp[l][r];
        if(s[l] == s[r])    return dp[l][r] = solve(l+1, r-1, s);

        int t1 = 1 + solve(l+1, r, s);
        int t2 = 1 + solve(l, r-1, s);

        return dp[l][r] = min(t1, t2);
    }
    int minInsertions(string s) {
        n = s.size();
        dp.assign(n, vector<int>(n, -1));
        int ans = solve(0,n-1,s);
        return ans;
    }
};