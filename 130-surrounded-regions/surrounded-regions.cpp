class Solution {
public:
int m, n;

    void dfs(vector<vector<char>> &board, int i, int j){
        if(board[i][j]=='O'){
            board[i][j]='1';

            if(i+1<m)   dfs(board, i+1, j);
            if(i>1) dfs(board, i-1, j);
            if(j+1<n)   dfs(board, i, j+1);
            if(j>1) dfs(board, i, j-1);
        }
    }

    void solve(vector<vector<char>>& board) {
        if(board.size()==0)  return;

        m= board.size();
        n= board[0].size();

        for(int i=0; i<m; i++){
            dfs(board, i, 0);
            dfs(board, i, n-1);
        }
        for(int i=1; i<n-1; i++){
            dfs(board, 0, i);
            dfs(board, m-1, i);
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]=='O')   board[i][j]='X';
                else if(board[i][j]=='1')    board[i][j]='O';
            }
        }
    }
};