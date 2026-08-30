class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0, msum = nums[0];
        int ansStart = 0, ansEnd = 0;
        int start = 0;

        for(int i=0; i<n; i++){
            sum += nums[i];
            if(sum > msum){
                msum = sum;
                ansStart = start;
                ansEnd = i;
            }
            if(sum < 0){
                sum = 0;
                start = i+1;
            }
        }
        return msum;
    }
};