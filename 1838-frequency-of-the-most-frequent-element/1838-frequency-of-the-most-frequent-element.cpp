class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        // int ans = 0;
        // int maxx = *max_element(nums.begin(), nums.end());
        // int diff = 0;
        // for(int i=0; i<n; i++){
        //     diff = maxx - nums[i]; 
        //     if(diff <= k){ 
        //         ans++;
        //         k -= diff;
        //     }
        // }
        // return ans;

        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0, r = 0;
        int ans = 0;
        long long sum = 0;
        while(r < n){
            sum += nums[r];
            long long cost = 1LL * nums[r]*(r-l+1) - sum;

            while(cost > k){
                sum -= nums[l];
                l++;
                cost = 1LL*nums[r]*(r-l+1) - sum;
            }
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};