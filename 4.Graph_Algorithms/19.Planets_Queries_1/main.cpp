#include <bits/stdc++.h>
using namespace std;

// Binary Lifting in graphs
/*
we don't need to run dfs here
for initialisation of the table we just need to add 2^0 i.e. immediate parent of every node first then run a 
for loop to fill other cells in table

Once the table is filled - then you can make jumps, find lca, ..
*/



const int mxN = 2e5+10;
const int mxD = 30; //ceil(log2(10^9))
int n, q;

// parent matrix where [i][j] corresponds to i's (2^j)th parent
int parent[mxN][mxD];

int jump(int a, int d){
    for(int i = 0; i<mxD; i++)
        if(d&(1<<i)) a = parent[a][i];
    return a;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>q;
    for(int i = 1; i<= n; i++) cin>>parent[i][0];

    //evaluate the parent matrix
    for (int d = 1; d < mxD; d++)
    {
        for (int i = 1; i <= n; i++)
        {
            parent[i][d] = parent[parent[i][d-1]][d-1];       
        }
    }
    // process queries
    while (q--)
    {
        int a, d;
        cin>>a>>d;
        cout<<jump(a, d)<<"\n";
    }
    
}

