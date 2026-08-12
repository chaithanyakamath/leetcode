class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans;
        unordered_map<int, int>mp;

        for(auto &m : matches){
            mp[m[0]]; // lists all players played
            mp[m[1]]++; // lists players who lost how many times
        }
        vector<int> a,b;
        for(auto [pl, lost]: mp){
            if(lost == 0)   a.push_back(pl);
            if(lost == 1)   b.push_back(pl);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        ans.push_back(a);
        ans.push_back(b);

        return ans;
    }
};