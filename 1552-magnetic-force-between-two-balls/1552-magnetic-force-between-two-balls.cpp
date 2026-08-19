class Solution {
public:
int n;
    bool possible(int mid, vector<int>& positions, int m){
        int count = 1;
        int prev = positions[0];
        for(int i=1; i<n; i++){
            int curr = positions[i];
            if(abs(curr-prev) >= mid){   
                count++;
                prev = curr;
            }
        }
        return (count>=m);
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        n = position.size();
        int l = 1;
        int r = position[n-1] - position[0];
        int ans = 0;

        while(l <= r){
            int mid = l + (r-l)/2;
            if(possible(mid, position, m)){
                ans = mid;
                l = mid+1;
            }
            else    r = mid-1;

        }
        return ans;
    }
};