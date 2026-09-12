class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        priority_queue<pair<int, int>> pq;

        for(int n : nums)   mp[n]++;
        for(auto [val, frq]: mp){
            pq.push({frq, val});
        }

        vector<int> ans;
        while(k>0){
            k--;
            auto [frq, val] = pq.top();
            pq.pop();
            ans.push_back(val);
        }
        return ans;
    }
};