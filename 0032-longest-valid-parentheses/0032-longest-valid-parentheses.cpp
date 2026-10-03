class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int l = 0, r = 0;
        int ans = 0;
        string store = "";
        for(char c : s){
            if(c == '(')    l++;
            else r++;

            if(l == r)  ans = max(ans, l*2);
            else if(r>l)    l=r=0; // more open bracket than close
        }
        l=r=0;
        for(int i=n-1; i>=0; i--){
            if(s[i] == ')') r++;
            else l++;

            if(l == r)  ans=max(ans, l*2);
            else if(l > r)  l=r=0; // more closed bracket than open
        }
        return ans;
    }
};
// left to right scan might misses few valid one's due to extra '(', so scan from both end