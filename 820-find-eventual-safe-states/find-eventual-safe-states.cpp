class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& state) {
        state[node] = 1; 

        for (int nbr : graph[node]) {
            if (state[nbr] == 1) return true;         
            if (state[nbr] == 0 && dfs(nbr, graph, state))
                return true;
        }

        state[node] = 2;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> state(n, 0);

        for (int i = 0; i < n; i++) {
            if (state[i] == 0)
                dfs(i, graph, state);
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (state[i] == 2)
                ans.push_back(i);
        }
        return ans;
    }
};