#include <bits/stdc++.h>
using namespace std;


// operations on sorted sets and greedy algorithms with sorting

/*
input
3
1 2
2 4
4 4

a = (2,1, 0), (4,2, 1), (4,4, 2)
this is sorted a

now we are iterating over a and maintaining a set

s = {},  find lower_bound(1), s = {(2, 0)};
s = {(2, 0)}, find lower_bound(2), ans[a[i][2]] = 1, 
s = {(2,0), (4, 1)}, find lower_bound(4), --it, ans[a[i][2]] = (*it)[1], s.erase(it), s = {(2,0), (4, 1), (4, 0)}
*/


const int mxN = 2e5;
int n, ans[mxN];
array<int, 3> a[mxN];  // r, l, index

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>a[i][1]>>a[i][0];
        a[i][2] = i;
    }

    sort(a, a+n);

    set<array<int, 2>> s;
    for(int i = 0; i<n; i++){
        auto it = s.lower_bound({a[i][1]});
        // cout<<distance(s.begin(), it)<<endl;
        if(it!=s.begin()){ 
            --it;
            ans[a[i][2]] = (*it)[1];
            s.erase(it);
        }else{
            ans[a[i][2]] = s.size();
        }
        s.insert({a[i][0], ans[a[i][2]]});
    }

    cout<<s.size()<<"\n";
    for(int i = 0; i<n; i++){
        cout<<ans[i]+1<<" ";
    }

    return 0;
}