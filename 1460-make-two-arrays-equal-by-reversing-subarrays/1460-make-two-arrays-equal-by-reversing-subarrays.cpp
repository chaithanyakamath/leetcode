class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int n = target.size();
        // unordered_map<int, int> mp(n);

        // for(int n : target) mp[n]++;
        // for(int n : arr) mp[n]--;

        // for(auto p : mp){
        //     if(p.second > 1)    return false;
        // }
        // return true;

        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());

        for(int i=0; i<n; i++){
            if(target[i] != arr[i]) return false;
        }
        return true;
    }
};