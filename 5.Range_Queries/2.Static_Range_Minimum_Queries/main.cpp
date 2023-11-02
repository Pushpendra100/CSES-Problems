#include <bits/stdc++.h>
using namespace std;

int a[200005], seg[4*200005];

// Using segment trees
// min can be also found, sum can also be found like this

/*
time taken to build the tree is O(N)
and time taken to query segment tree is O(logN)

left child has index = 2*ind + 1;
while right child has index = 2*ind+2;

Max index can only be upto 4N in segment tree
*/


void build(int ind, int low, int high){
    if(low==high){
        seg[ind] = a[low];
        return;
    }
    int mid = (high + low)/2;
    build(2*ind+1, low, mid);
    build(2*ind+2, mid+1, high);
    seg[ind] = min(seg[2*ind+1], seg[2*ind+2]);
}

int query(int ind, int low, int high, int l, int r){
    if(low>=l && high<= r){
        //node completely lies inside the range
        return seg[ind];
    }
    if(high<l || low>r){
        //node does not lie in the range
        return INT_MAX;
    }
    // now overlapping condition
    int mid = (high + low)/2;
    int left = query(2*ind + 1, low, mid, l, r);
    int right = query(2*ind+2, mid+1, high, l, r);
    return min(left, right);
}

int main() {

    int n, q;
    cin>>n>>q;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    build(0, 0, n-1);
    while (q--)
    {
        int l, r;
        cin>>l>>r;
        --l, --r;
        cout<<query(0, 0, n-1, l, r)<<"\n";
    }
    

    return 0;
}