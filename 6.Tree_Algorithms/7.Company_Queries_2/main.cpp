#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=Ddpd6b1V5bY

// LCA using Binary Lifting
/*
to find lca let's say d is the difference in level of a and b where b is at higher level of tree
we need to make a jump of heighest length l such that
    - l is a power of 2
    - l <= d

    for e.g. d = 13 = (1101)
    thus d = 13   l = 8
         d = 5    l = 4
         d = 1    l = 1
    thus we will be able to cover d = 13 distance in logN time
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
        int x;
        cin>>x;
        tree[x].push_back(i+1);
        tree[i+1].push_back(x);
    }
    binary_lifting(1,0);
    while (q--)
    {
        int a, b;
        cin>>a>>b;
        cout<<LCA(a, b)<<"\n";
    }
    

    return 0;
}