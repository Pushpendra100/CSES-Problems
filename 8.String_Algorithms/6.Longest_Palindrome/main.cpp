#include <bits/stdc++.h>
using namespace std;


// Manacher's Algorithm - Finding all sub-palindromes in O(N)
// https://www.youtube.com/watch?v=ei7qghJEj4Y

struct m{
    vector<int> p;
    string s;

    m(string s){
        this->s = s;
        build(s);
    }

    vector<int> run_manacher(string s){
        int n = s.size();
        string s_ = "$" + s + "^";
        p.resize(n+2);
        int l = 1, r = 1;
        for (int i = 1; i <= n; i++)
        {
            p[i] = max(0, min(r-i, p[l + (r-i)]));
            while(s_[i-p[i]] == s_[i+p[i]]){
                p[i]++;
            }
            if(i + p[i]>r){
                l = i - p[i], r = i + p[i];
            }
        }

        return vector<int> (p.begin()+1, p.end() -1);
    }

    vector<int> build(string s){
        string t;
        for(auto c: s){
            t += string("#") + c;    // += using this is more efficient for large strings than t = t + string("#") + c;
        }
        auto res = run_manacher(t+"#");
        return res;
    }

    pair<int, int> lps_pos_len(){
        int mxPos = -1, mxLen = 0;
        for(size_t i = 0; i<p.size(); i++){
            if(i==0 || mxLen<(p[i]-1)){
                mxLen = p[i]-1;
                mxPos = i - (i+1)/2;
            }
        }
        return {mxPos, mxLen};
    }

    string lps(){

        int mxPos = -1, mxLen = 0;
        for(size_t i = 0; i<p.size(); i++){
            if(i==0 || mxLen<(p[i]-1)){
                mxLen = p[i]-1;
                mxPos = i;
            }
        }

        int start = (mxPos - mxLen)/2;
        int end = start + mxLen - 1;
        string lps_s;
        for(int i = start; i<=end; i++){
            lps_s += s[i];
        }
        return lps_s;
    }
};




int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin>>s;

    m M(s);

    cout<<(M.lps());
    return 0;
}