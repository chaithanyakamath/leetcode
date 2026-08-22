class Solution {
public:
    bool checkDivisibility(int n) {
        int curr = n;
        int sum = 0, prod = 1;
        while(curr > 0){
            int d = curr % 10;
            sum += d;
            prod *= d;
            curr /= 10;
        }
        return (n % (sum+prod))==0;
    }
};