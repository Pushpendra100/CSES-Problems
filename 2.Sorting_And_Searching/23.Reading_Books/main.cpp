#include <bits/stdc++.h>
using namespace std;

/*https://www.youtube.com/watch?v=Z98NA0F7C0s


There are two cases

first one 
    3
    2 8 3

        k    j
        8    2,3
        2,3  8

    time = 2*max(book)

second 
    5
    1 2 4 5

            k       j
            5       4
            4       2
            2       1
            1       5

        since 4 + 2 + 1 > 5 thus j can read the largest book in last
        we can get the answer by simply adding all the times

    while in the first case
        k   j
        8   3
        3   2
        2   

        but here 3+2 = 5 < 8 thus j can't read the largest book, thus above techniuqe does not work in this case
        here answer = 2*largest_book

        |--2--|---3---|      |---------8----------|   
        |---------8----------|--2--|---3---|
*/

#define ll long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin>>n;
    int a[n];
    ll s= 0;
    for(int i = 0; i<n; i++) cin>>a[i], s+=a[i];
    sort(a, a+n);   
    cout<<max(s, 2ll*a[n-1]);

    return 0;
}