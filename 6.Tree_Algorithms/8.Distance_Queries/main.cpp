#include <bits/stdc++.h>
using namespace std;

// Binary Lifting
// Distance between 2 nodes in a tree in O(logN)

// https://www.youtube.com/watch?v=VaC6cqY-q_s

/*
So the formula is 
    dist = level[a] + level[b] - 2*level[LCA]
*/


const int mxN = 2e5+1;
vector<int> tree[mxN];
int up[mxN][30]; //sparse table
vector<int> level(mxN);

void binary_lifting(int src, int par){
    up[src][0] = par;
    level[src] = level[par] + 1;
    for(int i = 1; i<20; i++){
        if(up[src][i-1]!=-1)
            up[src][i] = up[up[src][i-1]][i-1];
        else up[src][i] = -1;
    }
    for(int child: tree[src]){
        if(child != par)
            binary_lifting(child, src);
    }
}//O(NlogN) and space complexity = O(NlogN)

int ans_query(int node, int jump_required){
    if(node == -1 || jump_required == 0) return node;
    for(int i = 29; i>=0; i--){ //we are finding the leftmost set bit
        if(jump_required >= (1<<i)){  //1<<i works by index i.e. if i = 2, then 100, means 1 is on index 2
            return ans_query(up[node][i], jump_required - (1<<i));
        }
    }
}//O(logN)

int LCA(int a, int b){
    if(level[a] > level[b]) swap(a, b);
    int d = level[b] - level[a];
    while (d>0)
    {
        int i = log2(d);
        b = up[b][i];
        d -= (1<<i);
    }//O(logN)
    if(a==b) return a;
    for(int i = 29; i>=0 ; i--){
        if(up[a][i] != -1 && (up[a][i] != up[b][i])){
            a = up[a][i], b = up[b][i];
        }
    }//O(logN)
    return up[a][0];
} // O(logN)

int main() {

    int n, q;
    cin>>n>>q;
    for(int i = 1; i<=n-1;i++){
        int x, y;
        cin>>x>>y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    binary_lifting(1,0);
    while (q--)
    {
        int a, b;
        cin>>a>>b;
        cout<<level[a] + level[b] - 2*level[LCA(a, b)]<<"\n";
    }
    

    return 0;
}