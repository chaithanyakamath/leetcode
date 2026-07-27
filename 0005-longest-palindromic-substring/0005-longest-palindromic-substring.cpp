class Solution {
public:
int n;
vector<vector<int>> dp;
    bool solve(const string &str, int i, int j){
        if(i >= j)  return true;
        if(str[i] != str[j])    return false;

        if(dp[i][j] != -1)  return dp[i][j];
        return dp[i][j] = solve(str, i+1, j-1);
    }
    string longestPalindrome(string s) {
        n = s.size();
        int maxLen = INT_MIN, spoint = 0;
        dp.assign(n, vector<int>(n, -1));
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(solve(s, i, j)){
                    if(j - i + 1 > maxLen){
                        maxLen = j - i + 1;
                        spoint = i;
                    }
                };
            }
        }
        return s.substr(spoint, maxLen);
    }
};