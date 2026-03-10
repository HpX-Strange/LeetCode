class Solution {
public:
int m,n;

    bool safe(int i, int j, vector<vector<int>>& grid){
        int count=0;
        for(int k=0; k<n; k++){
            if(grid[i][k]){
                count++;
            }
        }
        for(int k=0; k<m; k++){
            if(grid[k][j]){
                count++;
            }
        }
        if(count>2){
            return false;
        }
        return true;
    }

    int numSpecial(vector<vector<int>>& mat) {
        m= mat.size();
        n=mat[0].size();
        int count=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]){
                    if(safe(i,j, mat)){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};