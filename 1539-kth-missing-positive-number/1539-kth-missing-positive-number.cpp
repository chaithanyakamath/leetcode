class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int num = 1;
        for(int i=0; i<n; i++){
            while(arr[i] != num){
                k--;
                if(k == 0)  return num;
                num++;
            }
            num++;
        }
        return num + k-1;
    }
};