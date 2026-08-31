class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && st.top() > prices[i]) st.pop();

            if(!st.empty()) ans[i] = prices[i] - st.top();
            else ans[i] = prices[i];

            st.push(prices[i]);
        }

        // for(int i=0; i<n; i++){
        //     ans[i] = prices[i];
        //     for(int j=i+1; j<n; j++){
        //         if(j>i && prices[j] <= prices[i]){
        //             ans[i] = prices[i] - prices[j];
        //             break;
        //         }
        //     }
        // }
        return ans;
    }
};