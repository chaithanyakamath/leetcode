class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        long long ans = 0, pairs = 0;
        int l = 0;

        for(int r=0; r<n; r++){
            pairs += mp[nums[r]]; // possible pairs to be made
            mp[nums[r]]++;
            while(pairs >= k){
                ans += n-r; // if u find a good subarray thn adding anything to it still makes it good

                mp[nums[l]]--;
                pairs -= mp[nums[l]];
                l++;
            }
        }
        return ans;
    }
};