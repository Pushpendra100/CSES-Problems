#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=kzeAHV2Pw2o

// Retrieve any cycle in a directed graph
// DFS

// in round trip 1 it was undirected graph but now we have directed graph


// when we are applying dfs and putting in the stack we put true in its vis and in stack
// when its all children ends then we remove it from stack and rsFlag becomes false
// but when going through the children of a particular node we come to a node whose vis is true as well as its rsFlag is true this 
// tells that we have achieved a cycle and then we will print this cycle after reversing



#define endl "\n"
#define int long long int

int n, m;
vector<vector<int>> g;
vector<int> vis;
stack<int> recursionStack;
vector<bool> rsFlag; // this keeps track that node is present in the recursion stack or not


bool dfs(int u){
    vis[u] = true;
    recursionStack.push(u);
    rsFlag[u] = true;
    for(auto v: g[u]){
        if(!vis[v]){
            if(dfs(v)) return true;
        }
        if(rsFlag[v]){
            recursionStack.push(v);
            return true;
            // no more dfs
        }
    }
    recursionStack.pop();
    rsFlag[u] = false;
    return false;

}


// all connected components
void visit_all(){
    for (int u = 1; u <= n; u++)
    {
        if(!vis[u]){
            if(dfs(u)) break; // we got cycle
        }
    }
}



int32_t main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


    cin>>n>>m;
    g.resize(n+1);
    vis.resize(n+1);
    rsFlag.resize(n+1);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin>>a>>b;
        g[a].push_back(b);
    }
    visit_all();

    if(recursionStack.empty()){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }

    //cycle retrieval
    vector<int> ans;
    int temp = recursionStack.top();
    while(!recursionStack.empty())
    {
        ans.push_back(recursionStack.top());    
        recursionStack.pop();
        if(ans.back()==temp && ans.size() != 1) break;
    }
    reverse(ans.begin(), ans.end());
    cout<<ans.size()<<endl;
    for(auto u:ans){
        cout<<u<<" ";
    }
    

    return 0;
}