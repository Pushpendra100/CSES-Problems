#include <bits/stdc++.h>
using namespace std;

// Binary Lifting :- dynamic programming on trees

// https://www.youtube.com/watch?v=FAfSArGC8KY

const int mxN = 2e5+1;
vector<int> tree[mxN];
int up[mxN][20];

void binary_lifting(int src, int par){
    up[src][0] = par;
    for(int i = 1; i<20; i++){
        if(up[src][i-1]!=-1)
            up[src][i] = up[up[src][i-1]][i-1];
        else up[src][i] = -1;
    }
    for(int child: tree[src]){
        if(child != par)
            binary_lifting(child, src);
    }
}//O(NlogN)

int ans_query(int node, int jump_required){
    if(node == -1 || jump_required == 0) return node;
    for(int i = 19; i>=0; i--){ //we are finding the leftmost set bit
        if(jump_required >= (1<<i)){  //1<<i works by index i.e. if i = 2, then 100, means 1 is on index 2
            return ans_query(up[node][i], jump_required - (1<<i));
        }
    }
}//O(logN)

int main() {

    int n, q;
    cin>>n>>q;
    for(int i = 1; i<=n-1;i++){
        int x;
        cin>>x;
        tree[x].push_back(i+1);
        tree[i+1].push_back(x);
    }
    binary_lifting(1,-1);
    while (q--)
    {
        int a, b;
        cin>>a>>b;
        cout<<ans_query(a, b)<<"\n";
    }
    

    return 0;
}