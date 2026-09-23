class Solution {
public:
int n;
vector<string> ans;
string cur;
    bool isValid(string s){
        int len = s.size();
        if(s[0] == '0' && s.size() > 1) return false;
        int num = stoi(s);
        if(num < 0 || num > 255)    return false;
        return true;
    }
    void solve(int i, string s, int part, string cur){
        if(part==0){
            if(i == n){
                cur.pop_back();
                ans.push_back(cur);
            }
            return;
        }
        if(i<n) solve(i+1, s, part-1, cur+s.substr(i,1)+".");
        if(i+2 <= n && isValid(s.substr(i,2)))   solve(i+2, s, part-1, cur+s.substr(i,2)+".");
        if(i+3 <= n && isValid(s.substr(i,3)))   solve(i+3, s, part-1, cur+s.substr(i,3)+".");
    }
    vector<string> restoreIpAddresses(string s) {
        n = s.size();
        solve(0, s, 4, cur);
        return ans;
    }
};