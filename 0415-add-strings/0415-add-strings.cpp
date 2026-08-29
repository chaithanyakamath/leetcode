class Solution {
public:
    string addStrings(string num1, string num2) {
        int n = num1.size();
        int m = num2.size();

        string ans;
        int i = n-1, j = m-1;
        int carry = 0;
        while(i>=0 || j>=0 || carry){
            int sum = carry;
            if(i >= 0)  sum += num1[i]-'0';
            if(j >= 0)  sum += num2[j]-'0';

            carry = sum/10;
            sum %= 10;

            ans += char(sum + '0');
            i--; j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};