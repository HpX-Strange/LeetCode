class Solution {
public:
    int m,n;

    bool isSafe(int i, int j){
        return i>=0 && i<m && j>=0 && j<n;
    }
    vector<vector<int>> directions{{-1,0},{0,-1},{1,0},{0,1}};
    void dfs(vector<vector<int>>& grid, int i, int j, set<pair<int,int>> &visited){
        if(!isSafe(i,j) ||  grid[i][j]==0 || visited.find({i,j})!=visited.end()){
            return;
        }
        visited.insert({i,j});
        for(auto &dir: directions){
            int new_i= i+ dir[0];
            int new_j= j+ dir[1];

            dfs(grid, new_i, new_j, visited);
        }
    }
    int bfs(vector<vector<int>>& grid, set<pair<int,int>> &visited){
        queue<pair<int, int>> que;
        for(auto &it: visited){
            que.push(it);
        }
        int level=0;

        while(!que.empty()){
            int n= que.size();
            while(n--){
                pair<int, int> p= que.front();
                que.pop();

                int x= p.first;
                int y= p.second;

                for(auto &dir: directions){
                    int new_x= x+dir[0];
                    int new_y= y+dir[1];

                    if(isSafe(new_x, new_y) && visited.find({new_x, new_y})== visited.end()){
                        if(grid[new_x][new_y]==1){
                            return level;
                        }
                        visited.insert({new_x, new_y});
                        que.push({new_x, new_y});
                    }
                }
            }
            level++;
        }
        return level;
    }

    int shortestBridge(vector<vector<int>>& grid) {
        m= grid.size();
        n=grid[0].size();

        set<pair<int,int>> visited;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    dfs(grid, i, j, visited);
                    return bfs(grid, visited);
                }
            }
        }
        return -1;
    }
};