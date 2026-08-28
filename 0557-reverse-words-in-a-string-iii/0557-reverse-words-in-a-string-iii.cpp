class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        string ans = "";

        while(ss >> word){
            int n = word.size();
            int l = 0, r = n-1;
            while(l < r){
                swap(word[l], word[r]);
                l++; r--;
            }
            ans += word + " ";
        }
        ans.pop_back();
        return ans;
    }
};