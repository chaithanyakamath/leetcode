class Solution {
public:
int n;
vector<vector<int>> dp;
    int solve(const string &s, int i, int prev){
        // n = s.size();
        if(i == n)  return 0;
        if(dp[i][prev] != -1)   return dp[i][prev];
        if(s[i] == '0'){
            if(prev == 0){
                return dp[i][prev] = min(solve(s, i+1, 0), 1+solve(s,i+1,1));
            }
            else{   
                return dp[i][prev] = 1 + solve(s, i+1, 1);
            }
        }
        else{
            if(prev == 0){
                return dp[i][prev] = min(solve(s, i+1,1), 1 + solve(s,i+1,0));
            }
            else{
                return dp[i][prev] = solve(s, i+1, 1);
            }
        }
    }
    int minFlipsMonoIncr(string s) {
        n = s.size();
        dp.assign(n+1, vector<int>(2, -1));
        return solve(s,0,0);
    }
};