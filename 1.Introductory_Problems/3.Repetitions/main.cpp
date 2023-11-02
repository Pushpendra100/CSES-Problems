#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {

    string s;
    cin>>s;
    int ct = 0;
    int mx = 0;
    // type returned by size() function is  unsigned long int thus for comparision we need both to be of same type
    for (int i = 0, n = s.size(); i < n; i++)
    {   
        // on accessing -1 index in a string it will give null 
        if(s[i]==s[i-1]){
            ct++;
        }else{
            mx = max(mx, ct);
            ct = 1;
        }
    }
    mx = max(mx, ct);
    cout<<mx;

    return 0;
}