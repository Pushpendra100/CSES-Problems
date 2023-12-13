#include <bits/stdc++.h>
using namespace std;

// video solution - https://www.youtube.com/watch?v=kZfm68XKC58

// Bellman ford
// print the negative cycle

/*
Bellman-Ford algorithm for SSSP

Recap of Bellman Ford
- N-1 relaxations can achieve propagation in a -ve edge but no -ve cycle scenario
- After the above step, N-1 relaxations can be used to detect and propagate -INF arising due to all -ve cycles
- Thus, it takes 2*(N-1) relaxation to detect all -INF hotspots
*/

/*
Obersvation 1
the graph can be disconnected with A the starting vertex
Therefore, we will consider a vertex A' which is connected to all vertices with edge weighted 0
Thus all vertexed will be marked 0 instead of INF
and understand relaxations as -ve Distances

Observation 2
Negative cycle can be detected in Nth relaxation cycle itself
    - that is if there is a relaxation beyond (N-1)th iteration, there is a negative cycle

Observation 3
Relaxation in the Nth iteration, the relaxed vertex is of the following two forms
    - vertex belongs to a negative cycle
    - there is a -ve cycle leading to this particular vertex. We use these concepts later


Question: How do we ensure that we capture a vertex that is part of the negative cycle and not the type 2?
    - Why do we even need this vertex to be part of -ve cycle?
        we can cycle through it to print the cycle
    - Ensuring the vertex - two step process
        - Step 1; capture parent
            dist[v] = dist[u] + edge_distance(u, v)
            then u is relaxant of v
            relaxant[v] = u
            significance of relaxant : If a particular vertex got marked as -INF; its relaxant is responsible
        - Step 2; traceback relaxants to arrive at vertex of type 1
            how many tracebacks to land up in the cycle?
            n-1 tracebacks for the worst case 
        
*/

#define endl "\n"
#define int long long int

struct triplet{
    int first;
    int second;
    int third;
};

int n, m;
vector<triplet> edges;
vector<int> dist;
vector<int> relaxant;

void bellman_ford(){
    int x = -1;
    for(int i = 1; i<=n; i++){ //n iterations of relaxation
        x = -1; //each itr starts with a reset of x
        for(auto e:edges){
            int u = e.first;
            int v = e.second;
            int d = e.third;

            if(dist[u] + d < dist[v]){
                dist[v] = d + dist[u];
                relaxant[v] = u;
                x = v;  // x will be keeping the vertex which relaxed in the nth iteration
                // and if there were no cycle then in nth iteration this will be -1
            }
        }
    }

    //after the nth cycle
    if(x==-1) cout<<"NO"<<endl;  //no negative cycle
    else{
        // there is negative cycle
        // n relaxant trace back - to end up in a node which is part of cycle
        for(int i = 1; i<= n; i++){
            x = relaxant[x];
        }
        // now x is a node which is part of negative cycle

        //capturing the negative cycle
        vector<int> cycle;
        for(int v = x; ;v = relaxant[v]){
            // until x reoccurs 
            cycle.push_back(v);
            if(v==x && cycle.size() > 1) break;
        }
        reverse(cycle.begin(), cycle.end());

        cout<<"YES"<<endl;
        for(auto elem : cycle){
            cout<<elem<<" ";
        }
    }
}

int32_t main() {

    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    cin>>n>>m;
    dist.resize(n+1);
    relaxant.resize(n+1);
    edges.resize(m);
    for (int i = 0; i < m; i++)
    {
        struct triplet inp;
        cin>>inp.first>>inp.second>>inp.third;
        edges[i] = inp;
    }
    for (int i = 1; i <=n; i++)
    {
        relaxant[i] = -1;
    }
    bellman_ford();
    

    return 0;
}