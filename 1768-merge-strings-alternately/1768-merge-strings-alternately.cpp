class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        string ans = "";
        if(n==1 && m==1)    return word1+word2;

        int i = 0, j = 0;
        int count = 1;
        while(i < n && j < m){
            if(count % 2 != 0){  
                ans += word1[i];
                i++;
            }
            else{
                ans += word2[j];
                j++;
            }
            count++;
        }
        if(i < n)   ans += word1.substr(i, n-1);
        if(j < m)   ans += word2.substr(j, m);

        return ans;
    }
};