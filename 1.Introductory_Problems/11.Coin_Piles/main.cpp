#include <bits/stdc++.h>
using namespace std;

/*
observation1 - max pile can't exceed twice times the min
observation2 - in one move we are removing a total of 3 coins thus if total coins are multiple of 3 then they can be removed completely
*/

int main() {

    int t;
    cin>>t;
    while (t--)
    {
        int a, b;
        cin>>a>>b;
        if(b>a) swap(a,b);
        if(a>2*b || (a+b)%3 != 0)
        {
            cout<<"NO"<<"\n";
        }
        else{
            cout<<"YES"<<"\n";
        } 
    }

    return 0;
}