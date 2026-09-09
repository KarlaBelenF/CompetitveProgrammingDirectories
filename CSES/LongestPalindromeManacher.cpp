#include <bits/stdc++.h>
using namespace std;
vector<int> manacher(const string& s) {
    if (s.empty()) return {};
    string t = "^#";
    for (char c : s) {
        t += c;
        t += "#";
    }
    t += "$";

    int n = t.length();
    vector<int> P(n, 0);
    int C = 0;
    int R = 0;
    for (int i = 1; i < n - 1; i++) {
        int espejo = 2 * C - i;
        if (i < R) {
            P[i] = min(R - i, P[espejo]);
        }
        while (t[i + 1 + P[i]] == t[i - 1 - P[i]]) {
            P[i]++;
        }
        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }
    }
    return P;
}
void solve() {
    string s; cin>>s;
    vector<int>pal = manacher(s);
    int ans=0, ansi;
    for(int i=0; i<pal.size(); i++)
    {
        if(pal[i]>ans)
        {
            ansi=i;
            ans=pal[i];
        }
    }
    ansi=(ansi-1-pal[ansi])/2;
    //cout<<ansi<<" "<<endl;
    cout<<s.substr(ansi,ans)<<endl;
}
 
int main() {ios::sync_with_stdio(false);cin.tie(nullptr);
    int t=1; //cin>>t;
    while(t--)// && t!=0)
    {
        solve();
    }
    return 0;
}
