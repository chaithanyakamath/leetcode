class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        priority_queue<int> pq;

        for(int n : nums)   pq.push(n);

        while(k > 0){
            k--;
            int curr = pq.top();
            pq.pop();
            ans += curr;
            pq.push((curr+2)/3);
        }
        return ans;
    }
};