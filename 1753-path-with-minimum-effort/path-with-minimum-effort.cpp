class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{-1,0},{0,-1},{1,0},{0,1}};
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        pq.push({0, 0, 0});
        dist[0][0] = 0;
        
        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            
            int effort = curr[0];
            int u = curr[1];
            int v = curr[2];
            
            
            if(u == m-1 && v == n-1)
                return effort;
            
            for(auto &dir : directions) {
                int new_u = u + dir[0];
                int new_v = v + dir[1];
                
                if(new_u >= 0 && new_v >= 0 && new_u < m && new_v < n) {
                    int wt = abs(heights[new_u][new_v] - heights[u][v]);
                    int new_effort = max(effort, wt);
                    
                    if(new_effort < dist[new_u][new_v]) {
                        dist[new_u][new_v] = new_effort;
                        pq.push({new_effort, new_u, new_v});
                    }
                }
            }
        }
        
        return 0; 
    }
};