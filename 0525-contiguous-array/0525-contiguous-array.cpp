class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int balance = 0, ans = 0;
        mp[0] = -1;

        for(int i=0; i<n; i++){
            if(nums[i] == 0)  balance--;
            else balance++;

            if(mp.count(balance))   ans = max(ans, i-mp[balance]);
            else mp[balance] = i;
        }
        return ans;
    }
};