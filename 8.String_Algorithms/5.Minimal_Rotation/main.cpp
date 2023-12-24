#include <bits/stdc++.h>
using namespace std;


// Booth's algorithm for lexicographically least rotation of a string = O(n)
// https://github.com/Ashishgup1/Competitive-Coding/blob/master/String%20Rotation%20(Booth%27s%20Algorithm).cpp

//Returns the lexicographically least rotation of a string
string least_rotation(string s){
    s += s;
    vector<int> f(s.size(), -1);
    int k = 0;
    for (size_t j = 1; j < s.size(); j++)
    {
        char sj = s[j];
        int i = f[j-k-1];
        while (i != -1 && sj!=s[k+i+1])
        {
            if(sj<s[k+i+1]) k = j-i-1;
            i = f[i];
        }
        if(sj != s[k+i+1]){
            if(sj<s[k]) k = j;
            f[j-k] = -1;
        }else{
            f[j-k] = i+1;
        }
    }
    return s.substr(k, s.size()/2);
}
// Time complexity = O(n)

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin>>s;
    cout<<least_rotation(s)<<"\n";    

    return 0;
}