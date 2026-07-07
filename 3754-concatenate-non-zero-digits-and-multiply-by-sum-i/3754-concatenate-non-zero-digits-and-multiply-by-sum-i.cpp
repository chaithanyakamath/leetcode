class Solution {
public:
    long long sumAndMultiply(int n) {
        long long num=0, sum=0;
       
       for(char ch : to_string(n)){
            if(ch != '0'){
                num = num*10 + ch - '0'; // -'0' to convert back to int
                sum += ch - '0';
            }
       }
        return num*sum;
    }
};