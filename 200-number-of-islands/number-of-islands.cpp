class Solution {
public:
int m;
int n;

void dfs(vector<vector<char>>& grid, int i, int j){
    if(i>=m || j>=n || j<0 || i<0|| grid[i][j]=='0') return;
    grid[i][j]='0';
    dfs(grid,i,j+1);
    dfs(grid,i,j-1);
    dfs(grid,i+1,j);
    dfs(grid,i-1,j);
}
    int numIslands(vector<vector<char>>& grid) {
        m= grid.size();
        n= grid[0].size();
        int ans=0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};