class NumMatrix {
public:
int m, n;
vector<vector<int>> pre;
    NumMatrix(vector<vector<int>>& matrix) {
        m= matrix.size();
        n= matrix[0].size();
        pre.resize(m, vector<int>(n));
        pre[0][0]= matrix[0][0];
        for(int i=1; i<m; i++){
            pre[i][0]= pre[i-1][0]+matrix[i][0];
        }
        for(int j=1; j<n; j++){
            pre[0][j]= pre[0][j-1]+ matrix[0][j];
        }
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                pre[i][j]=matrix[i][j]+pre[i-1][j]+ pre[i][j-1]- pre[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(row1==0 && col1==0)  return  pre[row2][col2];
        if(row1==0) return pre[row2][col2]-pre[row2][col1-1];
        if(col1==0) return pre[row2][col2]- pre[row1-1][col2];
        return pre[row2][col2]-pre[row1-1][col2]-pre[row2][col1-1]+pre[row1-1][col1-1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */