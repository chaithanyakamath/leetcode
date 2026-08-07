class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int i=n; i<100; i++){
            int cur = i;
            int mult = 1;
            while(cur > 0){
                int d = cur%10;
                mult *= d;
                cur /= 10;
            }
            if(mult%t == 0) return i;
        }
        return 100;
    }
};