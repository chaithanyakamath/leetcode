class Solution {
public:
    bool check(vector<int>& freq){
        for(int n : freq){
            if(n > 0)  return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<int> freq(128, 0);

        for(char c : t) freq[c]++;

        int i=0, j=0;
        int start = 0;
        int len = INT_MAX;
        string ans = "";
        while(j < n){
            freq[s[j]]--;

            while(check(freq)){   
                if(j-i+1 < len){
                    len = j-i+1;
                    start = i;
                }
                freq[s[i]]++;
                i++;
            }
            j++;
        }
        return (len == INT_MAX)? "" : s.substr(start,len);
    }
};