#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?app=desktop&v=CkJRXaQw8BA

/*
idea is to increase a window and update it from the left as we see a number repeating
for checking that a number is repeating in the window we have created a map
*/

const int mxN = 2e5;
int n, p[mxN];

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    map<int, int> mp; //storing frequency
    for(int i = 0; i<n; i++) cin>>p[i];
    int ans = 0;
    // j is maintaining the right point of the window while i is maintaining the left point of window
    for(int i = 0, j = 0; i<n; i++){
        while(j<n&&mp[p[j]]<1){
            mp[p[j]]++;
            ++j;
        }
        ans = max(j-i, ans);
        mp[p[i]]--;
    }
    cout<<ans<<"\n";
    return 0;
}