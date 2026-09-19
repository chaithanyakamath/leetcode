class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        int n =  words.size();
        vector<string> ans;

        for(string s : words){
            mp[s]++;
        } 
        vector<pair<string, int>> store(mp.begin(), mp.end());

        sort(store.begin(), store.end(), [](pair<string, int>&a, pair<string, int> &b){ // a & b are 2 pairs to be compared
            if(a.second ==  b.second)   return a.first < b.first; //lexicographical chk if same freq(return one with lesser lexographic val)
            return a.second > b.second; //different freq(return one with more freq)
        });  // lambda func

        for(int i=0; i<k; i++)  ans.push_back(store[i].first);
        return ans;
    }
};