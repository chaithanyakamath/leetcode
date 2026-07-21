class Solution {
public:
    int n;
    vector<vector<int>> dp;
    bool solve(vector<int>& nums, int target, int i){
        if(target == 0)   return true;
        if(i == n || target < 0)    return false;

        if(dp[i][target] != -1)   return dp[i][target];
        bool take = solve(nums, target - nums[i], i+1);
        bool skip = solve(nums, target, i+1);
         
        return dp[i][target] = take || skip;
    }
    bool canPartition(vector<int>& nums) {
        n = nums.size();
        int sum = 0;
        for(int n : nums)   sum += n;
        dp.assign(n+1, vector<int>((sum/2)+1, -1));
        
        if(sum % 2)   return false;
        else{
            return solve(nums,sum/2,0);
        }
    }
};