#include <bits/stdc++.h>
using namespace std;


// 2SAT 
// (x1 ∨ y1) ∧ (x2 ∨ y3) ∧ (x4 ∨ y4) ∧ (x5 ∨ y5)

int n, m, v;
vector<vector<int>> adj, adj_t;
stack<int> s;
vector<bool> vis, assignment;
vector<int> comp;

void dfs1(int u){
    vis[u] = true;
    for(int v: adj[u]){
        if(!vis[v]) dfs1(v);
    }
    s.push(u);
}
void dfs2(int u, int j){
    comp[u] = j;
    for(int v: adj_t[u]){
        if(comp[v]==-1) dfs2(v, j);
    }
}

bool solve_2SAT(){
    vis.assign(v, false);
    for(int i = 0; i<v; i++){
        if(!vis[i]) dfs1(i);
    }
    comp.assign(v, -1);
    int j = 0;
    
    while (!s.empty())
    {
        int t = s.top();
        s.pop();
        if(comp[t]==-1) dfs2(t, j);
        j++;
    }
    assignment.assign(v/2, false);
    for (int i = 0; i < v; i+=2)
    {
        if(comp[i]==comp[i+1]) return false;
        assignment[i/2] = comp[i] < comp[i+1]; //given problem is not satisfiable
        // here i+1 is the real one and i is the negation of it
    }
    return true; // given problem is satisfiable
    
}


void add_disjunction(int a, int na, int b, int nb){
    // na and nb signify whether a and b are to be negated
    // when a +ve then na = 1 otherwise 0
    a = 2*a ^ na;
    b = 2*b ^ nb;
    int neg_a = a ^ 1;
    int neg_b = b ^ 1;
    adj[neg_a].push_back(b);
    adj[neg_b].push_back(a);
    adj_t[b].push_back(neg_a);
    adj_t[a].push_back(neg_b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    v = 2*m;
    adj.resize(v), adj_t.resize(v);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        char c1, c2;
        cin>>c1>>a>>c2>>b;
        add_disjunction(--a, c1=='+',--b, c2=='+');
    }
    
    bool ans = solve_2SAT();
    //here vertices will be 2m and edges will be 2n
    //O(V+E) is the time complexity
    if(ans){
        for(auto elem : assignment){
            if(elem) cout<<'+'<<" ";
            else cout<<'-'<<" ";
        }
    }else{
        cout<<"IMPOSSIBLE\n";
    }

    return 0;
}