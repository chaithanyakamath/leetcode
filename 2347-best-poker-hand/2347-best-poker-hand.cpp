class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        vector<int> mp1(26);
        unordered_map<int, int> mp2;

        for(char c : suits) mp1[c-'a']++;
        for(int n : ranks)  mp2[n]++;

        for(int val : mp1)  if(val >=5) return "Flush";

        bool ans = false;
        for(auto [key, val] : mp2){
            if(val >= 2)    ans = true;
            if(val >= 3)    return "Three of a Kind";
        }
        return (ans)? "Pair" : "High Card";
    }
};