class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> mp1(256, -1), mp2(256, -1);
        int n = s.size();

        for(int i=0; i<n; i++){
            if(mp1[s[i]] != -1 && mp1[s[i]] != t[i])  return false;
            if(mp2[t[i]] != -1 && mp2[t[i]] != s[i])  return false;

            mp1[s[i]] = t[i];
            mp2[t[i]] = s[i];
        }
        return true;
    }
};