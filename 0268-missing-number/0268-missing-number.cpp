class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int missing = 0;

        for(int i=0; i<n; i++)  missing ^= nums[i]; // xor with all values in nums
        for(int i=1; i<=n; i++)  missing ^= i; // xor with values in range [0,n] inclusively which gives u the missing one's

        return missing;
    }
};