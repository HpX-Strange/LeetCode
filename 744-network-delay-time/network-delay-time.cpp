class Solution {
public:

    void dji(int source, vector<int> &distance, vector<vector<pair<int,int>>> &adj){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.emplace(0, source);      //priority_queue-> distance then node
    distance[source]=0;
    while(!pq.empty()){
        int d= pq.top().first;
        int node= pq.top().second;
        pq.pop();
        if(d>distance[node])    continue;
        for(auto &nbr: adj[node]){
            int adj_node= nbr.first;
            int wt= nbr.second;
            if(d+wt< distance[adj_node]){
                distance[adj_node]= d+wt;
                pq.emplace(d+wt, adj_node);
            }
        }
    }
}

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0; i<times.size(); i++){
                int u=times[i][0];
                int v= times[i][1];
                int w= times[i][2];
                adj[u].push_back({v,w}); 
        }
        vector<int> distance(n+1, INT_MAX);
        dji(k, distance, adj);
        int ans=INT_MIN;
        for(int i=1; i<distance.size(); i++){
            if(distance[i]==INT_MAX){
                return -1;
            }
            ans= max(ans, distance[i]);
        }
        return ans;
   }
};