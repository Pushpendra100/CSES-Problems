#include <bits/stdc++.h>
using namespace std;

// william lin solution

const int mxN = 2e5;/* condition */
int n, q, dt, t[mxN], d[mxN], rt[mxN], rp[mxN], cr[mxN], ds[mxN], de[mxN], cs[mxN]; //t-next node, d - depth of a node, rt - root of a node, rp - position of root of a node , cr- cycle root, ds - start timer, de - end timer, cs - cycle size
vector<int> adj[mxN], cyc; // adj[mxN] - capture node which are before of it 
bool vis[mxN];

void dfs1(int u){
    ds[u] = dt++;
    for(int v: adj[u]){
        if(rt[v]^v){
            d[v] = d[u]+1;
            rt[v] = rt[u];
            cr[v] = cr[u];
            dfs1(v);
        }
    }
    de[u] = dt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>q;
    for(int i = 0; i<n; i++){
        cin>>t[i]; --t[i];
        adj[t[i]].push_back(i);
    }
    memset(rt, -1, 4*n);  
    /*
    The reason for using 4 * n instead of just n is related to the size of the data type.
    The reason for using 4 * n is often seen in scenarios where you're dealing with arrays of integers, and each integer is 4 bytes (32 bits) or another data type that is larger than a byte. Using 4 * n ensures that you are setting n integers (or elements of a larger data type) rather than n bytes.
    */
    for(int i = 0; i<n; i++){
        if(~rt[i]) continue;
        int u = i;
        while (!vis[u])
        {
            vis[u] = 1;
            u = t[u];
        }
        while (!cyc.size()||u^cyc[0])
        {
            rp[u] = cyc.size();
            cyc.push_back(u);
            rt[u] = u;
            cr[u] = i;
            u = t[u];
        }
        for(int ci: cyc){
            dt = 0;
            dfs1(ci);
            cs[ci] = cyc.size();
        }
        cyc.clear();
    }
    while (q--)
    {
        int a, b;
        cin>>a>>b, --a, --b;
        int ans = -1;
        if(cr[a]==cr[b]){
            if(rt[b]==b){
                ans = d[a];
                a = rt[a];
                ans += (rp[b]-rp[a]+cs[a])%cs[a];
            }else{
                if(rt[a]==rt[b] && ds[b]<=ds[a]&&ds[a]<de[b]){
                    ans = d[a] - d[b];
                }
            }
        }
        cout<<ans<<"\n";
    }
    
    return 0;
}