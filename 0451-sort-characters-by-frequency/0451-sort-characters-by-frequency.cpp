class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        unordered_map<char, int> mp;

        for(char c : s){
            mp[c]++;
        }
        vector<pair<char, int>> store(mp.begin(), mp.end());
        sort(store.begin(), store.end(), [](const auto &a, const auto &b){
            return a.second > b.second;
        });

        string ans = "";
        for(int i=0; i<store.size(); i++){
            while(store[i].second > 0){
                ans += store[i].first;
                store[i].second--;
            }
        }
        return ans;
    }
};