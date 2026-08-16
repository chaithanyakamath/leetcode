class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int maxx = *max_element(nums.begin(), nums.end());
        long long count = 0, frq = 0;
        int l = 0;

        for(int r=0; r<n; r++){
            if(nums[r] == maxx) frq++;
            while(frq >= k){
                if(nums[l] == maxx) frq--;
                l++;
            }
            count += l;
        }
        return count;
    }
};