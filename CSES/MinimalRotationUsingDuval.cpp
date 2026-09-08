#include <bits/stdc++.h>
using namespace std;

int duval(string s) //devuelve indice de inicio de minima rotacion
{
    int n=s.size()/2;
    int i = 0;
    int j = 1;
    
    while(i < n && j < n)
    {
        int k = 0;
        while (k < n && s[i + k] == s[j + k]) {
            k++;
        }
        if (k == n) break; 
        if (s[i + k] > s[j + k]) {
            i = i + k + 1;
        } 
        else {
            j = j + k + 1;
        }
        if (i == j) {
            j++;
        }
    }
    return min(i, j);
}

void solve() {
    string s; cin>>s;
    s+=s;
    int i=duval(s);
    cout<<s.substr(i,s.size()/2)<<endl;
}
 
int main() {ios::sync_with_stdio(false);cin.tie(nullptr);
    int t=1; //cin>>t;
    while(t--)//cin>>t && t!=0)
    {
        solve();
    }
    return 0;
}
