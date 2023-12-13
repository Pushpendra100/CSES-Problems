#include <bits/stdc++.h>
using namespace std;

// video solution - https://www.youtube.com/watch?v=009PBKHXtyA

/*
        General Dijkstras                   This Problem

    Dijkstras was about single source       Problem is about single source
    one shortest path.                      k shortest paths.

    We store the lengths in a vector        We can store k lengths for each vertex 
    We initialize all lengths to INF        in a vector of vectors. All k lengths are initialized to INF

    We overwrite when we find a shorter     If given path is better than the worst current path; we overwrite into 
    path                                    the worst current path; and sort as per path lengths                        


*/

#define endl "\n"
#define int long long int


const int INF = 1e18;
int n, m, k;
vector<vector<pair<int, int>>> g;
vector<vector<int>> dist;


void dij(){
    priority_queue<
        pair<int, int>,  //{cost, dest}
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;   // min heap

    pq.push({0, 1});  // initialise heap

    //retrieving from heap; rejecting if invalid
    while(!pq.empty()){
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        // dist[u][0] is the best path
        // dist[u][1] is the second best path
        // .
        // .
        // dist[u][k-1] is the kth best path
        if(dist[u][k-1] < d) continue;

        for(auto e:g[u]){
            int v = e.first;
            int c = e.second;

            if(dist[v][k-1] > c+d){
                dist[v][k-1] = c+d;
                pq.push({dist[v][k-1], v});
                sort(dist[v].begin(), dist[v].end());  // we sort to make dist[v][k-1] i.e kth deal the worst deal again
            }
        }
    }

}

int32_t main() {

    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    cin>>n>>m>>k;
    g.resize(n+1);
    dist.resize(n+1);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin>>a>>b>>c;
        g[a].push_back({b, c});
    }
    for(int i = 1; i<=n; i++){
        dist[i].resize(k);
        for (int j = 0; j < k; j++)
        {
            dist[i][j] = INF;
        }
    }
    dist[1][0] = 0;

    dij();

    for (int i = 0; i < k; i++)
    {
        cout<<dist[n][i]<<" ";
    }

    

    return 0;
}