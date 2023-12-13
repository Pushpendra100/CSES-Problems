#include <bits/stdc++.h>
using namespace std;

// Modified Dijkstras

// https://www.youtube.com/watch?v=Obwl9U6i-6o

/*
Conventional Dijkstras 
If we are able to optimize the path to V from origin by going through u:
    - Record the optimised cost
    - Push these details into a priority_queue for future processing
in conventional dijkstras we ignore this because we are finding the SSSP i.e. shortest path
if(dist[v]<=c+d) continue

c is the cost to reach u and d is the cost to reach from u to v and cost[v] is the current cost to reach v
scenario 1:-
proposed cost is > current cost
if(c+d > cost[v]) continue;
nothing to do here

scenario 2:-
proposed cost is == current cost
if(c+d == cost[v]){
    route[v] += route[u];
    route[v] %= mod;
    min_f[v] = min(min_f[v], min_f[u]+1);
    max_f[v] = max(max_f[v], max_f[u]+1);
}

scenario 3:-
we have discovered a new optimal cost
if(c+d < cost[v]){
    cost[v] = c+d;
    route[v] = route[u];
    min_f[v] = min_f[u] + 1;
    max_f[v] = max_f[v] + 1;
    pq.push({cost[v], v});
}
*/

#define int long long int
#define endl "\n"

const int M = 1e9+7;
const int INF = 1e17;
const int mxN = 1e5+1;
int n, m;
vector<vector<pair<int, int>>> g(mxN);
vector<int> cost(mxN), route(mxN), min_f(mxN), max_f(mxN);


void dijkstras(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});

    cost[1] = 0;
    route[1] = 1;

    while (!pq.empty())
    {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if(d>cost[u]) continue;

        for(auto e: g[u]){
            int v = e.first;
            int c= e.second;

            if(c+d>cost[v]) continue;
            if(c+d == cost[v]){
                route[v] += route[u];
                route[v] %= M;
                min_f[v] = min(min_f[v], min_f[u]+1);
                max_f[v] = max(max_f[v], max_f[u]+1);
            }
            if(c+d < cost[v]){
                cost[v] = c+d;
                route[v] = route[u];
                min_f[v] = min_f[u] + 1;
                max_f[v] = max_f[u] + 1;
                pq.push({cost[v], v});
            }
        }
    }
    
}

int32_t main() {

    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin>>a>>b>>c;
        g[a].push_back({b, c});
    }
    for(int i = 2; i<= n; i++){
        cost[i] = INF;
    }
    dijkstras();

    cout<<cost[n]<<" "<<route[n]<<" "<<min_f[n]<<" "<<max_f[n]<<endl;

    return 0;
}