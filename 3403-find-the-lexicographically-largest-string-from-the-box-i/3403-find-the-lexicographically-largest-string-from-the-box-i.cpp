class Solution {
public:
    string answerString(string word, int numFriends) {
        int  n = word.size();
        if(numFriends == 1) return word;

        int len = n-numFriends+1; // max substr len
        string ans = "";

        for(int i=0; i<n; i++){
            string curr = word.substr(i,min(len, n-i));
            if(curr > ans)  ans = curr;
        }
        return ans;
    }
};