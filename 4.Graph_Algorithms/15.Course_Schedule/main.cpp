#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=NLgYD6oFK2E

/*
// Topological Sort
    for topological sort graph must be DAG(Directed Acyclic Graph)
    (acyclic means no cycle)

It is a linear ordering of its vertices suct that for every directed edge uv 
for vertex u to v, u comes before vertex v in the ordering

There may be multiple such orders
*/

/*
InDegree
- incoming edges into the vertex

TopSort Algo :--
1. Record all inDegree of all vertices. Start with a vertex with 0 inDegree. Any such vertex
2. Remove the above vertex from the graph
3. Thus, the inDegree of every vertex that had a connection from the above vertex gets reduced by one
4. Keep repeating the above process untill the graph has no vertices/edges. Can't do this? There is no TopSort
*/


int n, m;
vector<vector<int>> g;
vector<int> degree;
priority_queue<int, vector<int>, greater<int>> noInDeg;
vector<int> ans;


int main() {

    cin>>n>>m;
    g.resize(n+1);
    degree.resize(n+1);

    //record inDegree while forming the graph
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin>>u>>v;
        g[u].push_back(v);
        ++degree[v];
    }

    //push all vertices with zero inDegree into a queue
    for (int i = 1; i <=n; i++)
    {
        if(!degree[i]) noInDeg.push(i);
    }
    
    //process vertices with zero inDegrees
    while(!noInDeg.empty()){
        int u = noInDeg.top();
        noInDeg.pop();
        ans.push_back(u);
        for(auto v: g[u]){
            --degree[v];
            if(!degree[v]) noInDeg.push(v);
        }
    }

    if(ans.size()!=n) cout<<"IMPOSSIBLE\n"; //this will be when there is some cycle present
    else{
        for(auto elem : ans){
            cout<<elem<<" ";
        }
    }
    

    return 0;
}