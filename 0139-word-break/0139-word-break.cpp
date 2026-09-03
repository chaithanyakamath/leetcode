class Solution {
public:
int n;
vector<int> dp;
    bool solve(int start, string s, vector<string>& dict){
        if(start == n)  return true;
        if(dp[start] != -1) return dp[start];
        for(int len = 1; start+len <= n; len++){
            string cur = s.substr(start, len);
            if(find(dict.begin(), dict.end(), cur) != dict.end()){    
                if(solve(start+len, s, dict))   return dp[start] = true;
            }
        }
        return dp[start] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
    n = s.size();
    dp.assign(n+1, -1);
    return solve(0, s, wordDict);
    }
};