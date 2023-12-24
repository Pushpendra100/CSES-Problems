#include <bits/stdc++.h>
using namespace std;

// KMP algorithm for string matching
// see in random_topics directory

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
} // O(N) - length of string s
// and space complexity of O(N);


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string t, s;
    cin>>t>>s;
    vector<int> lps = prefix_function(s); //lps - longest prefix sum or prefix function

    int ct = 0;
    int i = 0, j = 0;
    while (i<(int)t.size())
    {
        if(t[i]==s[j]){
            j++, i++;
        }else{
            if(j!=0) j = lps[j-1];
            else i++;
        }
        if(j==(int)s.size()){
            ct++;
        }
    }//O(t+s) time complexity
    
    cout<<ct<<"\n";

    return 0;
}

