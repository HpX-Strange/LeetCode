class Solution {
public:

    bool dfs(vector<vector<int>>& graph, int i, vector<bool> &visited, vector<bool> &one_path){
        visited[i]=true;
        one_path[i]=true;

        for(int &nbr: graph[i]){
            if(!visited[nbr]){
                if(dfs(graph, nbr, visited, one_path)){
                    return true;
                }
            }
            else if(one_path[nbr]){
                return true;
            }
        }
        one_path[i]=false;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();

        vector<bool> visited(n, false);
        vector<bool> one_path(n, false);
        bool cycle_found=false;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                if(dfs(graph, i, visited, one_path)){
                    cycle_found=true;
                }
            }
        }
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(one_path[i]==false){
                ans.push_back(i);
            }
        }
        return ans;
    }
};