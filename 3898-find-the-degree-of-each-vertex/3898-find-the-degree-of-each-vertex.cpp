class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ans;

        for(int i=0; i<n; i++){
            int count=0;
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 1)   count++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};