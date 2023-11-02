#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5;
int n, x, w[mxN];

int main() {

    cin>>n>>x;
    for (int i = 0; i < n; i++)
        cin>>w[i];
    sort(w, w+n);
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<w[i]<<" ";
    // }
    // cout<<endl;
    
    int ans = 0;
// 5 7 8 8 8 8 9 9 10 10 
// 0 1 2 3 4 5 6 7  8  9


    for (int i = 0, j=n-1; i < j;)
    {
        while (i<j&&w[i]+w[j]>x)
            --j;
        if(i>=j) break;
        ++ans;
        ++i, --j;
    }
    cout<<n-ans;    



    return 0;
}