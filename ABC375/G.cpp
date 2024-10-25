#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF = 1e18;

struct Road {
    int A;
    int B;
    ll C;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<Road> roads(M+1);
    for(int i=1; i<=M; ++i){
        cin >> roads[i].A >> roads[i].B >> roads[i].C;
    }

    vector<vector<pair<int, ll>>> adj(N+1);
    for(int i=1; i<=M; ++i){
        int u = roads[i].A;
        int v = roads[i].B;
        ll w = roads[i].C;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    auto dijkstra = [&](int src) -> vector<ll> {
        vector<ll> dist(N+1, INF);
        dist[src] = 0;
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, std::greater<pair<ll, int>>> pq;
        pq.emplace(0, src);
        while(!pq.empty()){
            auto [current_dist, u] = pq.top(); pq.pop();
            if(current_dist > dist[u]) continue;
            for(auto &[v, w] : adj[u]){
                if(dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w;
                    pq.emplace(dist[v], v);
                }
            }
        }
        return dist;
    };

    vector<ll> dist1 = dijkstra(1);
    vector<ll> distN = dijkstra(N);

    ll D = dist1[N];

    vector<bool> is_in_G(M+1, false);
    vector<vector<pair<int, int>>> gprime(N+1, vector<pair<int, int>>());
    for(int i=1; i<=M; ++i){
        int u = roads[i].A;
        int v = roads[i].B;
        ll w = roads[i].C;
        if( (dist1[u] + w + distN[v] == D) || (dist1[v] + w + distN[u] == D) ){
            is_in_G[i] = true;
            gprime[u].emplace_back(v, i);
            gprime[v].emplace_back(u, i);
        }
    }

    vector<bool> visited(N+1, false);
    vector<ll> dfs_num(N+1, 0);
    vector<ll> low(N+1, 0);
    int time_counter = 0;
    vector<bool> is_bridge(M+1, false);

    struct Frame {
        int node;
        int next_child;
        int parent;
        int parent_edge;
    };

    stack<Frame> stk;

    for(int u=1; u<=N; ++u){
        if(!visited[u]){
            stk.push(Frame{u, 0, -1, -1});
            while(!stk.empty()){
                Frame &current = stk.top();
                int node = current.node;
                if(!visited[node]){
                    visited[node] = true;
                    dfs_num[node] = low[node] = ++time_counter;
                }
                if(current.next_child < gprime[node].size()){
                    pair<int, int> edge = gprime[node][current.next_child];
                    current.next_child +=1;
                    int v = edge.first;
                    int road_id = edge.second;
                    if(v == current.parent){
                        continue;
                    }
                    if(!visited[v]){
                        stk.push(Frame{v, 0, node, road_id});
                    }
                    else{
                        low[node] = min(low[node], (ll)dfs_num[v]);
                    }
                }
                else{
                    stk.pop();
                    if(current.parent != -1){
                        low[current.parent] = min(low[current.parent], low[node]);
                        if(low[node] > dfs_num[current.parent]){
                            is_bridge[current.parent_edge] = true;
                        }
                    }
                }
            }
        }
    }

    for(int i=1; i<=M; ++i){
        if(is_in_G[i] && is_bridge[i]){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
    }

    return 0;
}