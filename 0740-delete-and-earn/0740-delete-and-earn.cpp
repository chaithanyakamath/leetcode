class Solution {
public:
    vector<int> dp;
    int solve(vector<int> &store, int i){
        if(i >= store.size())   return 0;

        if(dp[i] != -1) return dp[i];
        int take = store[i] + solve(store, i+2);
        int skip = solve(store, i+1);

        return dp[i] = max(take, skip);
    }
    int deleteAndEarn(vector<int>& nums) {
        int maxx = *max_element(nums.begin(), nums.end());
        vector<int> store(maxx+1,0);
        for(int n : nums)      store[n] += n;
        dp.assign(store.size()+1, -1);

        return solve(store,0);
    }
};