class Solution {
public:
int n;
int dp[101][101][2];
    int solve(vector<int>& piles, bool alice, int i, int m){
        if(i >= n)  return 0;
        if(dp[i][m][alice] != -1)   return dp[i][m][alice];

        int stones = 0;
        int res = (alice)? -1 : INT_MAX;
        for(int x=1; x<=(2*m);x++){
            if(i+x-1 < n)   stones += piles[i+x-1];
            if(alice){
                res = max(res, stones + solve(piles, 0,i+x, max(m,x)));
            }
            else{
                res = min(res, solve(piles, 1, i+x, max(m,x)));
            }
        }
        return dp[i][m][alice] = res;
    }
    int stoneGameII(vector<int>& piles) {
       n = piles.size();
       memset(dp, -1, sizeof(dp));
       return solve(piles,1,0,1); 
    }
};