class Solution {
public:
    int t[51][51][51];
    const int mod= 1e9+7;
    int solve(int i, int j, int m, int n, int moves){
        if(i<0 || i>=m ||j<0 || j>=n){
            return 1;
        }
        if(moves==0)    return 0;
        if(t[i][j][moves]!=-1) return t[i][j][moves];
        int right= solve(i, j+1, m, n, moves-1);
        int left= solve(i, j-1, m, n, moves-1);
        int up= solve(i-1,j, m, n, moves-1);
        int down= solve(i+1, j, m, n, moves-1);
        return t[i][j][moves]= ((up+down)%mod +(left+right)%mod)%mod;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(t, -1, sizeof(t));
        return solve(startRow, startColumn, m, n, maxMove);
    }
};