class Solution {
public:
    bool check(vector<int>& mp){
        for(int n : mp){
            if(n != 0)  return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<int> mp(26,0);
        if(n > m)   return false;

        for(char c : s1)    mp[c-'a']++;

        int l = 0, r = 0;
        while(r<m){
            mp[s2[r]-'a']--;
            if(r-l+1 == n){
                if(check(mp))   return true;
                mp[s2[l]-'a']++;
                l++;
            }
            r++;
        }
        return false;
    }
};