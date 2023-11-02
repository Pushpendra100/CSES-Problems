#include <bits/stdc++.h>
using namespace std;

#define ll long long

// int main() {

//     int n;
//     cin>>n;
//     int a[n+1];
//     a[0] = 0;
//     ll ct = 0;
//     for (int i = 1; i <= n; i++)
//     {
//         cin>>a[i];
//         if(a[i-1]>a[i]){
//             ct += a[i-1]-a[i];
//             a[i]=a[i-1];
//         }
//     }
//     cout<<ct<<endl;
//     return 0;
// }


//another way
int main(){
    int n;
    cin>>n;
    int mx = 0;
    ll ct = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        mx = max(mx, x);
        ct += mx - x;
    }
    cout<<ct;
}