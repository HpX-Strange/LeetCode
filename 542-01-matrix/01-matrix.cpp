class Solution {
public:
    int m,n;
    vector<vector<int>> directions{{-1,0}, {0,-1}, {1,0}, {0,1}};
    bool isSafe(int i, int j){
        return i>=0 && i<m && j>=0 && j<n;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        m= mat.size();
        n= mat[0].size();
        queue<pair<int,int>> que;
        vector<vector<int>> result(m, vector<int>(n, -1));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]==0){
                    result[i][j]=0;
                    que.push({i,j});
                }
            }
        }
        while(!que.empty()){
            pair<int, int> q= que.front();
            que.pop();
            int i=q.first;
            int j=q.second;

            for(auto &dir: directions){
                int i_= i+dir[0];
                int j_= j+dir[1];

                if(isSafe(i_, j_) && result[i_][j_]==-1){
                    result[i_][j_]=result[i][j]+1;
                    que.push({i_, j_});
                }
            }
        }
        return result;

    }
};