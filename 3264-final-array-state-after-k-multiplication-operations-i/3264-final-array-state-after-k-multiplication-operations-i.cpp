class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> ans;
        for(int i=0; i<n; i++)   pq.push({nums[i], i});

        while(k--){
            auto [cur, idx] = pq.top();
            pq.pop();

            cur *= multiplier;
            nums[idx] = cur;
            pq.push({cur, idx});
        }
        return nums;
    }
};