class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m= grid.size();
        int n= grid[0].size();
        int count=0;
        vector<vector<int>> pre(m, vector<int>(n, 0));
        pre[0][0]=grid[0][0];
        if(pre[0][0]<=k)    count++;
        for(int i=1; i<n; i++){
            pre[0][i]=grid[0][i]+pre[0][i-1];
            if(pre[0][i]<=k){
                count++;
            }
        }
        for(int i=1; i<m; i++){
            pre[i][0]=grid[i][0]+pre[i-1][0];
            if(pre[i][0]<=k){
                count++;
            }
        }
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                pre[i][j]= pre[i-1][j]+pre[i][j-1]+grid[i][j]-pre[i-1][j-1];
                if(pre[i][j]<=k){
                    count++;
                }
            }
        }
        return count;
    }
};