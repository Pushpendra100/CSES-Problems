#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/blog/entry/44651

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int x = 0;
        for (int i = 0; i < n; i++)
        {
            int p;
            cin>>p;
            if(i&1){
                // consider stairs from 0 to n-1
                // we have to consider only odd stairs
                x^=p;
            }
        }
        cout<<(x?"first":"second")<<"\n";
    }
    

    return 0;
}