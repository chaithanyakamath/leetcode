class Solution {
public:
    int n; 
    unordered_map<int, int> mp;
    vector<vector<int>> dp;
    bool solve(vector<int>& stones, int csi, int prevJump){
        if(csi == n-1)  return true;
        if(dp[csi][prevJump] != -1) return dp[csi][prevJump];

        bool result = false;
        for(int nextJump = prevJump-1; nextJump <= prevJump+1; nextJump++){
            if(nextJump > 0){
                int nextStone = stones[csi] + nextJump;
                if(mp.find(nextStone) != mp.end())  result = result || solve(stones, mp[nextStone],nextJump);
            }
        }
        return dp[csi][prevJump] = result;
    }

    bool canCross(vector<int>& stones) {
        n = stones.size();
        if(stones[1] != 1)  return false;

        dp.assign(n, vector<int>(n+1, -1));

        for(int i=0; i<n; i++)  mp[stones[i]] = i;

        return solve(stones, 0, 0);
    }
};