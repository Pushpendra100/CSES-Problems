#include <bits/stdc++.h>
using namespace std;

// see book (competitive programmers handbook) page no. 237

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int x = 0; // x^0 = x
        for(int i = 0; i<n; i++){
            int a;
            cin>>a;
            x^=a;
        }
        // if x is non zero then winning state for player1 and if it is zero then it is losing state for player 1
        cout<<(x?"first":"second")<<"\n";
    }        

    return 0;
}