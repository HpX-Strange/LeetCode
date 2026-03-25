class Solution {
public:
int m, n;
int t[301][301];
    int solve(int i, int j, vector<vector<int>>& matrix){
        if(i<0 || i>=m || j<0 || j>=n || matrix[i][j]==0){
            return 0;
        }
        if(t[i][j]!=-1) return t[i][j];
        int right= solve(i, j+1, matrix);
        int down= solve(i+1, j, matrix);
        int diagonal= solve(i+1, j+1, matrix);

        return t[i][j]= min({right, down, diagonal}) + 1;
    }

    int countSquares(vector<vector<int>>& matrix) {
        memset(t, -1, sizeof(t));
        m= matrix.size();
        n= matrix[0].size();
        int ans=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]==1){
                    ans+= solve(i, j, matrix);
                }
            }
        }
        return ans;
    }
};