#include <bits/stdc++.h>
using namespace std;
// a bipartite graph is a graph that does not contain any odd-length cycles
// Divide given Graph into Bipartite sets - https://www.geeksforgeeks.org/divide-given-graph-into-bipartite-sets/
// Given a graph G(V, E), divide it into two sets such that no two vertices in a set are connected directly. If not possible print “Not Possible”.

/*
last bit of even numbers is 0
and last bit of odd numbers is 1

xor of two same numbers is 0 and of two different numbers is 1
1 1 - 0
0 0 - 0
1 0 - 1
0 1 - 1


-> xor of two same numbers is 0 ( x ^ x = 0)
-> xor of a number with 0 is the number itself (x^0 = x)
-> xor of a number with 1 is very interesting
    xor of a even number will increase the number with 1
    and xor of a odd number will decrease it by 1
    e.g. 2^1 = 3 while 3^1 = 2
        6^1 = 7 while 7^1 = 6


NOT Operator:--
    it will change the sign of the number and also decrease its value by 1
    e.g. ~1 = -2, ~2 = -3, ~(-2)=1, ~(-3) = 2, ~(-1) = 0
*/

const int mxN = 1e5;
int n, m, c[mxN];
vector<int> adj[mxN];

void dfs(int u, int cu = 0){
    if(~c[u]){ //runs when c[u] value is already set other than -1
        if(c[u]^cu){ // runs when c[u] and cu both are different i.e. contradiction is coming
            cout<<"IMPOSSIBLE\n";
            exit(0);
        }
        return;
    }
    c[u] = cu;
    for (int v : adj[u])
    {
        dfs(v, cu^1);
    }
    
}

int main() {

    cin>>n>>m;
    for (int i = 0, a, b; i < m; i++)
    {
        cin>>a>>b,--a,--b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(c, -1, 4*n);
    for (int i = 0; i < n; i++)
    {
        if(c[i]<0){
            dfs(i);
        }
    }
    for(int i = 0; i<n; ++i)
        cout<<c[i]+1<<" ";
    
    
    

    return 0;
}