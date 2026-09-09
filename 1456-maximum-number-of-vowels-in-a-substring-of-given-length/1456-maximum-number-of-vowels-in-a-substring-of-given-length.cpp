class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        bool vowels[26] = {false};
        vowels[0] = vowels[4] = vowels[8] = vowels[14] = vowels[20] = true;

        int l = 0, ans = 0, count = 0;
        for(int r=0; r<n; r++){
            if(vowels[s[r]-'a'])    count++;
            while(r-l+1 > k){
                if(vowels[s[l]-'a'])    count--;
                l++;
            }
            ans = max(ans, count);
        }
        return ans;
    }
};