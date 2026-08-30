class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = *max_element(nums.begin(), nums.end());
        int curMin = 1, curMax = 1;

        for (int n : nums) {
            if (n == 0) {
                curMin = 1;
                curMax = 1;
                continue;
            }

            int temp = curMax * n;
            curMax = max({n, curMax * n, curMin * n});
            curMin = min({n, temp, curMin * n}); // we store min bcoz at certain point -ve * -ve makes large positive

            res = max(res, curMax);
        }
        return res;
    }
};