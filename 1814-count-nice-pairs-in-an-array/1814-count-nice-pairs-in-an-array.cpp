class Solution {
public:
    int reverse(int num){
        int rev = 0;
        while(num > 0){
            rev = rev*10 + num%10;
            num /= 10;
        }
        return rev;
    }

    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        for(auto &n : nums)  n = n - reverse(n);

        unordered_map<int, int> mp;
        int result = 0;
        for(int n : nums){
            result = (result + mp[n]) % 1000000007;
            mp[n]++;
        }
        return result;
    }
};