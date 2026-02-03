class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int e= edges.size();
        int n= edges.size()+1;

        vector<vector<int>> adj(n+1);
        for(int i=0; i<e; i++){
            int u= edges[i][0];
            int v= edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=1; i<=n; i++){
            if(edges.size()==adj[i].size()){
                return i;
            }
        }
        return -1;
    }
};