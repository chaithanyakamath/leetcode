class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int l = 0;
        int len = 0;
        vector<int>store(26,0);

        for(int r=0; r<n; r++){
            store[s[r]-'a']++;
            while(store[s[r]-'a'] > 2){
                store[s[l]-'a']--;
                l++;
            }
            len = max(len, r-l+1);
        }
        return (len==0)? n : len;
    }
};