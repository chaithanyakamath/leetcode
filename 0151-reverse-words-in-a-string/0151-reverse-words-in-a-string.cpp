class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        vector<string> store;
        while(ss >> word){
            store.push_back(word);
        }
        reverse(store.begin(), store.end());
        string ans = store[0];
        for(int i=1; i<store.size(); i++){
            ans = ans + " " + store[i]; 
        }
        return ans;
    }
};