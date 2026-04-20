class Solution {
public:

    void solve(vector<vector<int>>& image, int i, int j, int newcolor, int oldcolor){
        if(i<0 || j<0 || i>=image.size() || j>=image[0].size() || image[i][j]!=oldcolor || image[i][j]==newcolor){
            return ;
        }
        image[i][j]=newcolor;
        solve(image, i-1, j, newcolor, oldcolor);
        solve(image, i+1, j, newcolor, oldcolor);
        solve(image, i, j-1, newcolor, oldcolor);
        solve(image, i, j+1, newcolor, oldcolor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        solve(image, sr, sc, color, image[sr][sc]);
        return image;
    }
};