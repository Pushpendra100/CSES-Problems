#include <bits/stdc++.h>
using namespace std;

//Euler Graph / Euler Ciruit - visit every edge once and starting and ending node must be same
// This is complete code for finding euler path or cicuit

const int mxN = 1e5+10;
int n, m, euler_start;
vector<vector<int>> g(mxN);

void dfs(int u, vector<bool> &vis){
    vis[u] = true;
    for(int v: g[u]){
        if(!vis[v]) dfs(v, vis);
    }
}

bool connectivity_check(){
    vector<bool> vis(mxN, false);
    int node = -1;
    for (int i = 1; i <= n; i++)
    {
        if(g[i].size()){
            node = i; // found a node to start dfse
            break;
        }
    }
    if(node==-1){
        return true; 
    }

    dfs(node, vis);

    for(int i = 1; i<=n ; i++){
        if(vis[i]==false && g[i].size()>0){ 
            return false; 
        }
    }
    euler_start = node;
    return true;
}

void euler(){
    int odd = 0;
    int v1 =-1, v2 = -1;
    for(int i = 1; i<=n; i++){
        if(g[i].size() & 1){
            odd++;
            if(v1==-1) v1 = i;
            else if(v2 == -1) v2 = i;
        }
    }
    if(odd>2){  
        cout<<"IMPOSSIBLE\n";
        return;
    }
    if(odd==2) g[v1].push_back(v2), g[v2].push_back(v1);
    stack<int> st;
    st.push(euler_start);
    vector<int> res;
    while (!st.empty())
    {
        int v = st.top();
        if(!g[v].size()){
            res.push_back(v);
            st.pop();
        }else{
            int lst = g[v].back();
            g[v].pop_back();
            g[lst].erase(find(g[lst].begin(), g[lst].end(), v));
            st.push(lst);
        }
    }
    
    if(odd==2){
        for (size_t i = 0; i + 1< res.size(); i++)
        {
            if((res[i]==v1 && res[i+1]==v2) || (res[i]==v2&&res[i+1]==v1)){
                vector<int> res2;
                for(size_t j = i+1; j<res.size(); j++) res2.push_back(res[j]);
                for(size_t j = 0; j<=i; j++) res2.push_back(res[j]);
                res = res2;
                break;
            }
        }
    }

    for(int x: res){
        cout<<x<<" ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    for(int i = 0; i<m; i++){
        int a, b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    bool check = connectivity_check();
    if(!check){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }

    euler();


    return 0;
}