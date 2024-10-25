#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF = 1e18;

struct Query {
    int type;
    int param1;
    int param2;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, Q;
    cin >> N >> M >> Q;

    struct Road {
        int A;
        int B;
        ll C;
    };

    vector<Road> roads(M+1);
    for(int i=1; i<=M; ++i){
        cin >> roads[i].A >> roads[i].B >> roads[i].C;
    }

    vector<Query> queries(Q);
    vector<int> closure_time(M+1, Q+1);
    for(int i=0; i<Q; ++i){
        int type;
        cin >> type;
        queries[i].type = type;
        if(type == 1){
            int road_id;
            cin >> road_id;
            queries[i].param1 = road_id;
            queries[i].param2 = -1;
            if(closure_time[road_id] > i+1){
                closure_time[road_id] = i+1;
            }
        }
        else{
            int x, y;
            cin >> x >> y;
            queries[i].param1 = x;
            queries[i].param2 = y;
        }
    }

    vector<vector<ll>> dist(N+1, vector<ll>(N+1, INF));
    for(int i=1; i<=N; ++i){
        dist[i][i] = 0;
    }

    for(int i=1; i<=M; ++i){
        if(closure_time[i] == Q+1){
            int A = roads[i].A;
            int B = roads[i].B;
            ll C = roads[i].C;
            if(C < dist[A][B]){
                dist[A][B] = C;
                dist[B][A] = C;
            }
        }
    }

    for(int k=1; k<=N; ++k){
        for(int i=1; i<=N; ++i){
            if(dist[i][k] == INF) continue;
            for(int j=1; j<=N; ++j){
                if(dist[k][j] == INF) continue;
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    vector<ll> answers;
    for(int q = Q-1; q >=0; --q){
        if(queries[q].type == 2){
            int x = queries[q].param1;
            int y = queries[q].param2;
            if(dist[x][y] < INF){
                answers.push_back(dist[x][y]);
            }
            else{
                answers.push_back(-1);
            }
        }
        else{
            int road_id = queries[q].param1;
            int A = roads[road_id].A;
            int B = roads[road_id].B;
            ll C = roads[road_id].C;

            if(C < dist[A][B]){
                dist[A][B] = C;
                dist[B][A] = C;
            }

            for(int u=1; u<=N; ++u){
                for(int v=1; v<=N; ++v){
                    if(dist[u][A] == INF || dist[B][v] == INF){
                        continue;
                    }
                    if(dist[u][v] > dist[u][A] + C + dist[B][v]){
                        dist[u][v] = dist[u][A] + C + dist[B][v];
                    }
                }
            }
            for(int u=1; u<=N; ++u){
                for(int v=1; v<=N; ++v){
                    if(dist[u][B] == INF || dist[A][v] == INF){
                        continue;
                    }
                    if(dist[u][v] > dist[u][B] + C + dist[A][v]){
                        dist[u][v] = dist[u][B] + C + dist[A][v];
                    }
                }
            }
        }
    }

    reverse(answers.begin(), answers.end());

    int answer_idx = 0;
    for(int q=0; q<Q; ++q){
        if(queries[q].type ==2){
            cout << answers[answer_idx++] << "\n";
        }
    }

    return 0;
}