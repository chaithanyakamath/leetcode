class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int n = words.size();
        int m = s.size();
        int ans = 0;

        for(int i=0; i<n; i++){
            string curr = words[i];
            for(int j=0; j<curr.size(); j++){
                if(curr[j] != s[j]) break;
                else if(curr[j] == s[j] && j == curr.size()-1)   ans++;
            }
        }
        return ans;
    }
};