#include <bits/stdc++.h>
using namespace std;

// Binary search
/*
Binary search is applied on monotonic functions

Observe that the time needed to create at least x products is monotonic. In other words, if the given
machines can create x products in y1 time, then the same machines can create at least x products in y2 > y1 time.
Using this property, we can binary search over the answer.

For some vaue we binary search for, ans, we are left with the task of checking whether we can create t products in ans time.To do this, observe that it's optimal for every machine to work simultaneously. Then 
in ans time, machine i can create [ans/ki] products.
Overall, the n machines can create summation from i=1 to n, [ans/ki] products. If the sum >=t, then ans is valid.

*/
#define ll long long

const int mxN = 2e5;
int n, t, a[mxN];


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>t;
    for(int i = 0; i<n;i++) cin>>a[i];
    ll lb = 1, rb = 1e18;
    while (lb<rb)
    {
        ll mb = (lb+rb)/2;
        ll s = 0;
        for(int i = 0; i<n; i++){
            s+=min(mb/a[i], (ll)1e9);
        }
        // cout<<lb<<" "<<mb<<" "<<rb<<endl;
        if(s>=t) rb = mb;
        else lb = mb+1;
    } // O(nlogn);
    cout<<lb;

    return 0;
}