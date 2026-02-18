class Solution {
public:
typedef long long ll;
const int MOD= 1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto& it: roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
        vector<ll> distance(n, LLONG_MAX);
        vector<ll> ways(n, 0);
        pq.push({0, 0});
        distance[0]=0;
        ways[0]=1;

        while(!pq.empty()){
            ll d=pq.top().first;
            int node= pq.top().second;
            pq.pop();
            for(auto &it: adj[node]){
                int v= it.first;
                ll wt= it.second;

                if(d+wt<distance[v]){
                    distance[v]= d+wt;
                    ways[v]=ways[node];
                    pq.push({d+wt, v});
                }
                else if(d+wt==distance[v]){
                    ways[v] = (ways[v] + ways[node]) % MOD;
                }
            }
        }
        return ways[n-1]%MOD;

    }
};