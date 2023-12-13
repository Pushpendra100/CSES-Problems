#include <bits/stdc++.h>
using namespace std;

// https://cp-algorithms.com/graph/edmonds_karp.html

/*
Max-flow min-cut algo
*/

#define ll long long 

int n, m;
const ll INF = 1e18+1;
const int mxN = 510;
ll capacity[mxN][mxN]; //stores the residual capacity of the network
// int adj[mxN][mxN];
vector<int> adj[mxN];
vector<pair<int, int>> edgesCut;

ll bfs(int s, int t, vector<int> &parent){
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, ll>> q;
    q.push({s, INF});
    while (!q.empty())
    {
        int cur = q.front().first;
        ll flow = q.front().second;
        q.pop();
        for(int next: adj[cur]){
            if(parent[next]==-1 && capacity[cur][next]){
                parent[next] = cur;
                ll new_flow = min(flow, capacity[cur][next]);
                if(next==t){
                    return new_flow;
                }
                q.push({next, new_flow});
            }
        }
    }
    
    return 0;
}   

// A DFS based function to find all reachable vertices from s.  The function
// marks visited[i] as true if i is reachable from s.
void dfs(int s, vector<bool> &visited){
    cout<<s<<" ";
    visited[s] = true;
    for(int v: adj[s]){
        if(capacity[s][v]&&!visited[v]){
            dfs(v, visited);
        }
    }
}

void minCut(int s, int t){
    ll flow = 0;
    vector<int> parent(n+1);
    ll new_flow;
    while((new_flow = bfs(s, t, parent))){
        flow += new_flow;
        int cur = t;
        while (cur != s)
        {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }
    // return flow;

    // flow is maximum now, find vertices reachable from s
    vector<bool> visited(n+1, false);
    cout<<"dfs "<<endl;
    dfs(s, visited);
    cout<<endl;
    // for(bool v: visited){
    //     cout<<v<<" ";
    // }

    for(int i = 1; i<=n; i++){
      for (int j = 1; j <=n; j++)
         if (visited[i] && !visited[j] && capacity[i][j])
              edgesCut.push_back({i, j});
    }
    return;
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin>>a>>b;
        c = 1;
        adj[a].push_back(b);
        adj[b].push_back(a);
        // adj[a][b] = 1;
        // adj[b][a] = 1;
        capacity[a][b] += c;
    }
    for(int i = 1; i<=n ;i++){
        cout<<i<<"  ";
        for(int x: adj[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    minCut(1, n);  // mincut to separate s and t
        for(int i = 1; i<=n ;i++){
        for(int j=1; j<=n; j++){
            cout<<capacity[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<edgesCut.size()<<"\n";
    for(auto e: edgesCut){
        cout<<e.first<<" "<<e.second<<" "<<capacity[e.first][e.second]<<"\n";
    }

    return 0;
}