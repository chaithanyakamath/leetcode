class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int count = 0;
        int l = 0;
        string ans = "";

        for(int r=0; r<n; r++){
            if(s[r] == '1') count++;
            while(count > k){
                if(s[l] == '1') count--;
                l++;
            }
            if(count == k){
                while(s[l] == '0')  l++;
                string curr = s.substr(l, r-l+1);
                if(ans == "" || curr.size() < ans.size() || (ans.size()==curr.size()) && curr < ans) ans = curr;
            }
        }
        return ans;
    }
};