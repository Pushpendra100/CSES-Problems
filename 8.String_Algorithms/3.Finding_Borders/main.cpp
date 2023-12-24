#include <bits/stdc++.h>
using namespace std;

// Z function 
// see in random_topics directory

vector<int> z_function(string &s){
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i<n; i++){
        if(i<r){
            z[i] = min(r - i, z[i-l]);
        }
        while (i+z[i]<n && s[z[i]]==s[i + z[i]]) z[i]++;
        if(i+z[i]>r){
            l = i;
            r = i + z[i];
        }
    }
    return z;
} // O(n) -> where n is the length of string s
// ans space complexity = O(n) for z array

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin>>s;
    int n = (int)s.size();
    vector<int> z = z_function(s);

    vector<int> borders;
    for (int i = 0; i < n; i++)
    {
        if(z[i]+i==n) borders.push_back(z[i]);
    }
    reverse(borders.begin(), borders.end());
    for(int border:borders){
        cout<<border<<" ";
    }


    return 0;
}