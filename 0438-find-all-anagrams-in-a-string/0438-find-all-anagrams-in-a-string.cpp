class Solution {
public:
    bool check(vector<int>& freq){
        for(int &n : freq) {
            if(n != 0)  return false;
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<int> ans;
        vector<int> freq(26, 0);

        for(char c : p) freq[c-'a']++;

        int i=0, j=0;
        while(j<n){
            freq[s[j]-'a']--;
            if(j-i+1 == m) {
                if(check(freq))    ans.push_back(i);
                freq[s[i]-'a']++;
                i++;
            }
            j++;
        }
        return ans;
    }
};