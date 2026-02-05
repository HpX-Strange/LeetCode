class Solution {
public:
int m,n;
    int dfs(vector<vector<int>>& grid, int i, int j){
        if(i<0 || i>=m|| j<0 || j>=n || grid[i][j]==0)    return 0;
        grid[i][j]=0;
        int area=1;
        area+=dfs(grid, i+1,j);
        area+=dfs(grid,i-1,j);
        area+=dfs(grid,i,j+1);
        area+=dfs(grid,i,j-1);
        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int maxarea=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    int area= dfs(grid, i, j);
                    maxarea= max(area,maxarea);
                }
            }
        }
        return maxarea;
    }
};