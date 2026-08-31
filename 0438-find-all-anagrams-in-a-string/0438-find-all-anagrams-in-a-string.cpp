class Solution {
public:
    bool check(vector<int>& mp){
        for(int n : mp){
            if(n != 0)  return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<int> mp(26,0);
        vector<int> ans;

        for(char c : p) mp[c-'a']++;
        int l = 0, r = 0;
        while(r<n){
            mp[s[r]-'a']--;
            if(r-l+1 == m){
                if(check(mp))  ans.push_back(l);
                mp[s[l]-'a']++;
                l++;
            }
            r++;
        }
        return ans;
    }
};