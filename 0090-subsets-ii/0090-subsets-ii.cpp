class Solution {
public:
int n;
vector<vector<int>> ans;
vector<int> store;
    void solve(int i, vector<int>& nums){
        ans.push_back(store);

        for(int j=i; j<n; j++){
            if(j > i && nums[j] == nums[j-1])   continue;
            store.push_back(nums[j]);
            solve(j+1, nums);
            store.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n = nums.size();
        sort(nums.begin(), nums.end());
        solve(0, nums);
        return ans;
    }
};