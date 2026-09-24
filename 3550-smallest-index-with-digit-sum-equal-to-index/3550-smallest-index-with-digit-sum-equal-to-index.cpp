class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        int ans = -1;

        for(int i=0; i<n; i++){
            int cur = nums[i];
            int sum = 0;
            while(cur > 0){
                int d = cur % 10;
                sum += d;
                cur /= 10;
            }
            if(sum == i){    
                ans = i;
                break;
            }
        }
        return ans;
    }
};