class Solution {
public:
int n;
vector<vector<int>> ans;
vector<int> store;
    void solve(int i, vector<int>& nums, vector<vector<int>>& ans){
        if(i == n){
            ans.push_back(nums);
            return;
        }
        for(int j=i; j<n; j++){
            swap(nums[i], nums[j]);
            solve(i+1, nums, ans);
            swap(nums[i], nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        solve(0, nums, ans);
        return ans;
    }
};