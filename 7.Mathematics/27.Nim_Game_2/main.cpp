#include <bits/stdc++.h>
using namespace std;

// Grundy numbers see book (competitive programmers handbook) page no. 238
// https://www.topcoder.com/thrive/articles/Algorithm%20Games

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
            x^=a%4;  // (a%4) if for calculating grundy number
            // we find out grundy numbers for each heap and xor of all grundy numbers is taken if it 0 then this is losing state else it is winning state
        }
        cout<<(x?"first":"second")<<"\n";
    }        

    return 0;
}