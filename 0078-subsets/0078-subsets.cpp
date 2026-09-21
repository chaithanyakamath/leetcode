class Solution {
public:
int n;
vector<vector<int>> ans;
vector<int> store;
    void solve(int i, vector<int>& nums, vector<vector<int>>& ans){
        if(i >= n){
            ans.push_back(store);
            return;
        }

        store.push_back(nums[i]);
        solve(i+1, nums, ans);

        store.pop_back();
        solve(i+1, nums, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        solve(0, nums, ans);
        return ans;
    }
};