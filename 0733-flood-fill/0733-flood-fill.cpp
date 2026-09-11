class Solution {
public:
int n, m;
    void dfs(vector<vector<int>>& image, int i, int j, int newColor, int OriginalColor){
        if(i<0 || i>=n || j<0 || j>=m || image[i][j]!=OriginalColor || image[i][j]==newColor)   return;
        image[i][j] = newColor;

        dfs(image, i+1, j, newColor, OriginalColor);
        dfs(image, i-1, j, newColor, OriginalColor);
        dfs(image, i, j+1, newColor, OriginalColor);
        dfs(image, i, j-1, newColor, OriginalColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        n = image.size();
        m = image[0].size();
        dfs(image, sr, sc, color, image[sr][sc]);
        return image;
    }
};