class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        for(char c : s)   mp[c]++;

        int curr = mp.begin()->second;
        for(auto [ch, frq]: mp){
            if(curr != frq) return false;
        }        
        return true;
    }
};