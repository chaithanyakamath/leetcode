class Solution {
public:
int n1, n2;
vector<vector<int>> dp;
    int solve(const string &word1, const string &word2, int i, int j){
        if(i == n1 || j == n2)  return 0;

        if(dp[i][j] != -1)  return dp[i][j];
        if(word1[i] == word2[j]) return dp[i][j] = (1 + solve(word1, word2, i+1, j+1));
        int t1 = solve(word1, word2, i+1, j);
        int t2 = solve(word1, word2, i, j+1);

        return dp[i][j] = max(t1, t2);
    } 
    int minDistance(string word1, string word2) {
        n1 = word1.size();
        n2 = word2.size();
        dp.assign(n1, vector<int>(n2, -1));
        int chk =  solve(word1, word2, 0, 0);
        int ans = 0;
        int deletions = n1 - chk;
        int insertions = n2 - chk;

        return deletions + insertions;
    }
};