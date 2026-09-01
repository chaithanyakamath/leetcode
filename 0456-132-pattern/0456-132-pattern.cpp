class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        int secondLargest = INT_MIN;

        for(int i=n-1; i>=0; i--){
            if(nums[i] < secondLargest) return true; // all 3 values r found
            while(!st.empty() && st.top() < nums[i]){
                secondLargest = st.top(); // largest is nums[i] n secondLargest is st.top() only smallest is yet to be found
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};
