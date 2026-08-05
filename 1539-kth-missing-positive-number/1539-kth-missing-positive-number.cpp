class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        // int num = 1;
        // for(int i=0; i<n; i++){
        //     while(arr[i] != num){
        //         k--;
        //         if(k == 0)  return num;
        //         num++;
        //     }
        //     num++;
        // }
        // return num + k-1;

        int mid = -1;
        int low = 0, high = n-1;
        while(low <= high){
            mid = low + (high-low)/2;
            int curMissing = arr[mid] - (mid+1);
            if(curMissing  >= k) high = mid-1;
            else low = mid+1;
        }
        return low + k;
    }
};