class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;

        for(string s : strs){
            string curr = s;
            sort(curr.begin(), curr.end());
            mp[curr].push_back(s); // sorted version of anagram will be same, so it maps to its other anagrams
        }

        for(auto [string, vect] : mp)   ans.push_back(vect);
        return ans;
    }
};