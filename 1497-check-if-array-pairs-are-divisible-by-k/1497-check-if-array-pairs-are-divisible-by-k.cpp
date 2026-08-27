class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int, int> mp;

        for(int i=0; i<n; i++){
            int rem = ((arr[i] % k)+k) % k;
            mp[rem] ++;
        }

        for(auto [rem, frq] : mp){
            int compliment = (k-rem) % k;
            if(rem == 0 || rem*2 == k){
                if(frq % 2 != 0)    return false;
            }
            else if(mp[compliment] != frq)   return false;
        }
        return true;
    }
};