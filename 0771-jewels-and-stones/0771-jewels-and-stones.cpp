class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        // vector<int> mp1(256, -1), mp2(256, -1);
        unordered_map<char, int> mp1, mp2;

        for(char c : jewels) mp1[c]++;
        for(char c : stones) mp2[c]++;

        int count = 0;
        for(auto [ch, frq] : mp1){
            if(mp2.find(ch) != mp2.end())   count += mp2[ch];
        }
        return count;
    }
};