#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=v3msjEfT40Y

/*
given 2 9 1 2 7
sort  1 2 2 7 9

now see
1        0, 1  -- when we don't take 1 or take 1
2         2           
      0-1  2-3  => merge them, we get, 0-3
2        2
      0-3  2-5  => merge them, 0-5
7        7
      0-5  7-12  => when there is difference of atleast2 that means we have got our answer
    i.e. min sum which we cannot make because the numbers that will come in next are greater thus they will only increase the value

*/

#define ll long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin>>n;
    vector<int> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];
    sort(a.begin(), a.end());

    if(a[0]>1){
        cout<<"1\n";
    }else{
        ll r = 0; // maximum value upto which we can make sum without missing any value from 0 to r
        for(int i = 0; i < n; i++){
            if(r+1<a[i]){
                cout<<r+1<<"\n";
                return 0;
            }
            r += a[i];
        }
        cout<<r+1<<"\n";
    }

    return 0;
}