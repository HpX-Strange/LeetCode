class Solution {
public:
int m,n;
int t[301][301];
    int solve(int i, int j, vector<vector<char>>& grid){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]=='0'){
            return 0;
        }
        if(t[i][j]!=-1) return t[i][j];
        int right= solve(i, j+1, grid);
        int down= solve(i+1, j, grid);
        int diagonal= solve(i+1, j+1, grid);

        return t[i][j]=min({right, down, diagonal})+1;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        memset(t, -1, sizeof(t));
        m= matrix.size();
        n= matrix[0].size();
        int ans=0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]=='1')
                    ans= max(ans, solve(i, j, matrix));
            }
        }
        return ans*ans;
    }
};