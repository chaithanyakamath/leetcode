class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        unordered_map<int, int> mp;
        stack<int> st;

        for(int i=m-1; i>=0; i--){
            while(!st.empty() && st.top() <= nums2[i])  st.pop();
            int currGreater = (st.empty()) ? -1 : st.top();
            mp[nums2[i]] = currGreater;
            st.push(nums2[i]);
        }

        vector<int> ans;
        for(int n : nums1){
            ans.push_back(mp[n]);
        }
        return ans;
    }
};