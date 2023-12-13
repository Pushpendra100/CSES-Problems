#include <bits/stdc++.h>
using namespace std;
// Finding a vertex from a given vertex in the min. distance possible 
// BFS and then returning the path

const int mxN = 1e5;
int n, m, p[mxN];
vector<int> adj[mxN], ans;

int main() {

    cin>>n>>m;
    for (int i = 0, a, b; i < m; i++)
    {
        cin>>a>>b, --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(p, -1, 4*n);
    queue<int> qu;
    qu.push(0);
    while (!qu.empty())
    {
        int u = qu.front();
        qu.pop();
        for (int v : adj[u])
        {
            if(p[v]<0){
                p[v] = u;
                qu.push(v);
            }
        }
    }
    if(p[n-1]<0){
        cout<<"IMPOSSIBLE";
    }else{
        // now backtrack
        int u = n-1;
        while (u)
        {
            ans.push_back(u);
            u = p[u];
        }
        ans.push_back(0);
        reverse(ans.begin(), ans.end());
        cout<<ans.size()<<"\n";
        for (int a : ans)
        {
            cout<<a+1<<" ";
        }
        
    }
    

    return 0;
}