class Solution {
public:
int n;
    bool solve(const string &str, int i, int j){
        if(i >= j)  return true;
        if(str[i] != str[j])    return false;

        return solve(str, i+1, j-1);
    }
    string longestPalindrome(string s) {
        n = s.size();
        int maxLen = INT_MIN, spoint = 0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(solve(s, i, j)){
                    if(j - i + 1 > maxLen){
                        maxLen = j - i + 1;
                        spoint = i;
                    }
                };
            }
        }
        return s.substr(spoint, maxLen);
    }
};