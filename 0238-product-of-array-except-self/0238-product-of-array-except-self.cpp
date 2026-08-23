class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1;
        vector<int> prefix(n), postfix(n);
        int pre = 1, post = 1;

        while(l<n && r>=0){
            pre *= nums[l];
            post *= nums[r];
            prefix[l] = pre;
            postfix[r] = post;
            l++; r--;
        }

        vector<int> ans;
        int a=1, b=1;
        for(int i=0; i<n; i++){
            if(i == 0){
                a = 1;
                b = postfix[i+1];
            }
            else if(i == n-1){
                b = prefix[i-1];
                a = 1; 
            }
            else{
                a = prefix[i-1];
                b = postfix[i+1];
            }
            ans.push_back(a*b);
        }
        return ans;
    }
};