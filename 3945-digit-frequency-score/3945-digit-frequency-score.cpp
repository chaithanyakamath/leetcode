class Solution {
public:
    int digitFrequencyScore(int n) {
        unordered_map<int, int> mp;
        int ans = 0;
        int cur = n;
        while(cur > 0){
            int d = cur % 10;
            mp[d]++;
            cur /= 10;
        }
        for(auto p : mp)    ans += p.first * p.second;
        return ans;
    }
};