#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 2e5+10;
int n, q;
ll x[mxN];

int main() {

    cin>>n>>q;
    for (int i = 1; i <= n; i++)
    {
        cin>>x[i];
        x[i]+= x[i-1];  //prefix sum
    }
    while (q--)
    {
        int a, b;
        cin>>a>>b, --a;
        cout<<x[b]-x[a]<<"\n";
    }
    

    return 0;
}