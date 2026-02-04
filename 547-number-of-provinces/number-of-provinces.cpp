class Solution {
public:
    void bfs(vector<vector<int>>& grid, int source, vector<bool>& visited){
        queue<int> q;
        q.push(source);
        visited[source]=true;
        while(!q.empty()){
            int current= q.front();
            q.pop();

            for(int i=0; i<grid[current].size(); i++){
                if(!visited[i] && grid[current][i]==1){
                    q.push(i);
                    visited[i]=true;
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& grid) {
        int n= grid.size();
        vector<bool> visited(n,false);
        int provinces=0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                bfs(grid, i, visited);
                provinces++;
            }
        }
        return provinces;
    }
};