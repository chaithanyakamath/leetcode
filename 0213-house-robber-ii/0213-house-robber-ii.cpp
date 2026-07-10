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
        if(n == 1)  return nums[0];

        vector<int> dummy1 = nums;
        vector<int> dummy2 = nums;
        dummy1.pop_back();
        dummy2.erase(dummy2.begin());

        dp.assign(dummy1.size()+1, -1);
        int a =  solve(dummy1, 0);

        dp.assign(dummy2.size()+1, -1);
        int b =  solve(dummy2, 0);

        return max(a,b);
    }
};