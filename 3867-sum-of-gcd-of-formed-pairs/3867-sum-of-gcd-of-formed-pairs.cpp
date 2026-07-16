class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        int maxx = nums[0];

        vector<int> store;
        for(int i=0; i<n; i++){
            if(nums[i] > maxx)  maxx = nums[i];
            int curr = gcd(nums[i], maxx);
            store.push_back(curr);
        }

        sort(store.begin(), store.end());
        int m = store.size();
        if(m % 2 == 1){
            store.erase(store.begin() + m/2);
            m--;
        } 

        int l = 0, r = m-1;
        long long sum = 0;
        while(l<=r){
            sum += gcd(store[l], store[r]);
            l++; r--;
        }
        return sum;
    }
};