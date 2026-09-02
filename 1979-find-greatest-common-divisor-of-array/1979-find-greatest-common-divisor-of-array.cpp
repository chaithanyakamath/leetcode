class Solution {
public:
    int findGCD(vector<int>& nums) {
        int minn = *min_element(nums.begin(), nums.end());
        int maxx = *max_element(nums.begin(), nums.end());

        int ans = min(minn, maxx);
        while(ans > 1){
            if(minn % ans == 0 && maxx % ans == 0) break;
            ans--;
        }
        return ans;
    }
};