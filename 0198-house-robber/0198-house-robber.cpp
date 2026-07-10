class Solution {
public:
    int n;
    vector<int> dp; // declare
    int solve(vector<int>& nums, int i){
        if(i >= nums.size())    return 0;

        if(dp[i] != -1) return dp[i]; // check
        int steal = nums[i] + solve(nums, i+2);
        int skip = solve(nums, i+1);

        return dp[i] = max(steal, skip); // store
    }
    int rob(vector<int>& nums) {
        n = nums.size();
        dp.assign(n+1, -1); // initialize
        return solve(nums, 0);
    }
};