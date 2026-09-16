class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        ans.insert(ans.end(), nums.begin(), nums.end());

        return ans;
    }
};