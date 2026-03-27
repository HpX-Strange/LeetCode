class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        vector<vector<int>> temp= mat;
        int n= mat[0].size();
        k= k%n;
            for(int i=0; i<mat.size(); i++){
                if(i%2==0){
                    rotate(mat[i].rbegin(), mat[i].rbegin()+k, mat[i].rend());
                }else{
                    rotate(mat[i].begin(), mat[i].begin()+k, mat[i].end());
                }
            }
        
        if(temp==mat){
            return true;
        }
        return false;
    }
};