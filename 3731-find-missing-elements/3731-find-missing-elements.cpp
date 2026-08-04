class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        sort(nums.begin(), nums.end());
        unordered_set<int> st(nums.begin(), nums.end());

        int minn = nums[0];
        int maxx = nums[n-1];

        for(int i=minn; i<maxx; i++){
            if(st.find(i) == st.end()) ans.push_back(i);
        }

        return ans;
    }
};