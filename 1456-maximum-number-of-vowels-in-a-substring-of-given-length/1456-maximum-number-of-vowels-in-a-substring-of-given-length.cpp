class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        bool vowels[26] = {false};
        vowels[0] = vowels[4] = vowels[8] = vowels[14] = vowels[20] = true;

        int j = 0, i = 0;
        int ans = 0;
        int count;
        while(j<n){
            if(vowels[s[j]-'a'])    count++;
            if(j-i+1 == k){
                ans = max(ans, count);
                if(vowels[s[i]-'a']) count--;
                i++;
            }
            j++;
        }
        return ans;
    }
};