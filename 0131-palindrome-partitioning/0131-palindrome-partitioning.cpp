class Solution {
public:
int n;
vector<vector<string>> ans;
vector<string> curLvl;
    bool isPalindrome(string s){
        int len = s.size();
        int l = 0, r = len-1;
        while(l<=r){
            if(s[l] != s[r])  return false;
            l++; 
            r--;
        }
        return true;
    }
    void solve(int i, string s){
        if(i >= n){
            ans.push_back(curLvl);
            return;
        }

        for(int j=i; j<n; j++){
            string cur = s.substr(i, j-i+1);
            if(isPalindrome(cur)){
                curLvl.push_back(cur);
                solve(j+1, s);
                curLvl.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        n = s.size();
        solve(0, s);
        return ans;
    }
};