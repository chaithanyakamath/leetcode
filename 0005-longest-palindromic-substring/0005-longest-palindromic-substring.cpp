class Solution {
public:
    bool solve(const string& s, int l, int r){
        if(l >= r)  return true;
        if(s[l] != s[r])    return false;
        return solve(s, l+1, r-1);
    }
    string longestPalindrome(string s) {
       int n = s.size();
       int maxLen = 0, sPoint = 0;
       for(int l=0; l<n; l++){
            for(int r=l; r<n; r++){
                if(solve(s,l,r)){
                    if(r-l+1 > maxLen){
                        sPoint = l;
                        maxLen = r-l+1;
                    }
                }
            }
       }
        return s.substr(sPoint, maxLen);
    }
};