class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for(int n : nums)   mp[n]++;

        vector<pair<int, int>> store(mp.begin(), mp.end());

        sort(store.begin(), store.end(),[](const auto& a, const auto& b){
            return a.second > b.second;
        });

        vector<int> ans;
        for(auto [key,val] : store){
            if(k == 0)    break;
            ans.push_back(key);
            k--;
        }
        return ans;
    }
};