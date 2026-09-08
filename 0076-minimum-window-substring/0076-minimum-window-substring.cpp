class Solution {
public:
    bool check(vector<int>& store){
        for(int n : store){
            if(n > 0)   return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<int> store(128, 0);

        for(char c : t) store[c]++;

        int l = 0, len = INT_MAX, start = 0;
        for(int r=0; r<n; r++){
            store[s[r]]--;
            while(check(store)){
                if(len > r-l+1){ 
                    len = r-l+1;
                    start = l;
                }
                store[s[l]]++;
                l++;
            }
        }
        return (len == INT_MAX)? "" : s.substr(start, len);
    }
};