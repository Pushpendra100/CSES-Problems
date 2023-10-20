#include <bits/stdc++.h>
using namespace std;

int main() {

    string s;
    cin>>s;

    int hsh[26] = {0};
    for (int i = 0, n=s.size(); i < n; i++)
    {
        hsh[s[i] - 'A']++;
    }
    string f,c, b;
    int ct = 0;
    for (int i = 0; i < 26; i++)
    {
        if(hsh[i]){
            if(hsh[i]%2==0){
                while (hsh[i]/2)
                {   
                    f += 'A' + i;
                    b += 'A' + i;
                    hsh[i] -= 2;
                }
            }else{
                ct++;
                while (hsh[i])
                {
                    c += 'A' + i;
                    hsh[i]--;
                }
            }
        }
    }
    if(ct>1){
        cout<<"NO SOLUTION"<<"\n";
    }else{
        reverse(b.begin(), b.end());
        cout<<f+c+b<<"\n";
    }
    
    
    return 0;
}