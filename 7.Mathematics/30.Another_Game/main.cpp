#include <bits/stdc++.h>
using namespace std;

// Removing 1 coin at a time from n heaps of coins 

/*
simple thinking
in case of heap with even no. of sticks
    - second will remove the last stick
and in case of heap with odd no. of stick
    - first will remove the last stick
Thus existence of heap with odd no. of sticks is the must condition for 1st player to win else 2nd player will win
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int x = 0; 
        for(int i = 0; i<n; i++){
            int a;
            cin>>a;
            if(a&1) x = 1;
        }
        cout<<(x?"first":"second")<<"\n";
    }        

    return 0;
}