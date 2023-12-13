#include <bits/stdc++.h>
using namespace std;

const int mxN= 2e5+1;
int n;
vector<int> nxt(mxN), d(mxN), cyc;
bool vis[mxN];
vector<int> before[mxN];

void dfs(int u){
    for(int v: before[u]){
        if(!d[v]){
            d[v] = d[u] + 1;
            dfs(v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        cin>>nxt[i];
        before[nxt[i]].push_back(i);
    }
    for(int i = 1; i<=n ;i++){
        if(d[i]) continue;
        int u = i;

        while (!vis[u])
        {
            vis[u] = 1;
            u = nxt[u];
        }
        while (!cyc.size() || u^cyc[0])
        {
            cyc.push_back(u);
            u = nxt[u];
        }
        for(int ci: cyc){
            d[ci] = cyc.size();
        }
        for(int ci: cyc){
            dfs(ci);
        }
        cyc.clear();
    }

    for(int i = 1; i<=n ;i++){
        cout<<d[i]<<" ";
    }

    return 0;
}