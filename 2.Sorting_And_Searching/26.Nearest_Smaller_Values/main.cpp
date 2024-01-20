#include <bits/stdc++.h>
using namespace std;

/*
a  =  2  5  1  4  8  3  2  5
nl = -1  0 -1  2 .....
like this we can get our answer

*/

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin>>n;
    int a[n], nl[n];
    for(int i = 0; i<n; i++){
        cin>>a[i];
        nl[i] = i-1;
        while(~nl[i]&&a[nl[i]]>=a[i]) //dp type solution
            nl[i] = nl[nl[i]];
        cout<<nl[i]+1<<" ";
    }

    return 0;
}