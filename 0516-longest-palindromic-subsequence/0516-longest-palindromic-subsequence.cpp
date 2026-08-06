class Solution {
public:
int n;
vector<vector<int>> dp;
    int solve(const string& s, const string& r, int i, int j){
        if(i >= n  || j >= n)   return 0;

        if(dp[i][j] != -1)  return dp[i][j];
        if(s[i] == r[j])    return  dp[i][j] = (1 + solve(s,r,i+1, j+1));
        int t1 = solve(s, r, i+1, j);
        int t2 = solve(s, r, i, j+1);

        return dp[i][j] = max(t1, t2);
    }
    int longestPalindromeSubseq(string s) {
       n = s.size();
       string r = s;
       reverse(r.begin(), r.end());
       dp.assign(n, vector<int>(n+1, -1));
       return solve(s,r,0, 0);

    }
};