#include <bits/stdc++.h>
using namespace std;

/*
5
4 2 1 5 3
 
these are the three rounds
1
2 3
4 5

<--------
  <-- 
4 2 1 5 3
    -
  ------>
------>  

our ans = backward arrows + 1;

but how we will get this no. of backward arrows

take example, 7 1 4 2 5 3 6
position of 3 is 6
position of 4 is 3

so, when poition of a is greater than position of a+1, thus gives the no. of backward arrows

thus we will maintain a position vector
*/

#define ll long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin>>n;
    vector<int> pos(n+1);
    for(int i = 1; i<=n; i++){
        int x; cin>>x;
        pos[x] = i;
    }
    int ans = 1;
    for(int i = 2; i<=n; i++){
        if(pos[i]<pos[i-1]) ans++;
    }
    cout<<ans<<"\n";
    return 0;
}