class Solution {
public:
int n, res;
    int solve(vector<int>& nums, int curMax, int curMin, int i){
        if(i == n)  return res;
        if (nums[i] == 0) {
            res = max(res, 0);
            return solve(nums, 1, 1, i + 1);
        }
        int temp = curMax * nums[i];
        curMax = max({curMax * nums[i], curMin * nums[i], nums[i]});
        curMin = min({temp, curMin * nums[i], nums[i]});

        solve(nums, curMax, curMin, i+1);
        res = max(res, curMax);
        return res;
    }
    int maxProduct(vector<int>& nums) {
        n = nums.size();
        if(n==1)    return nums[0];
        res = *max_element(nums.begin(), nums.end());
        return solve(nums, 1, 1, 0);
    }
};