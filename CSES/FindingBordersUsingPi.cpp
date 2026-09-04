#include <bits/stdc++.h>
using namespace std;
vector<int> calcular_pi(const string& P) {
    int m = P.length();
    vector<int> pi(m, 0);
    
    for (int i = 1; i < m; i++) {
        int j = pi[i - 1];
        while (j > 0 && P[i] != P[j]) {
            j = pi[j - 1];
        }
        if (P[i] == P[j]) {
            j++;
        }
        pi[i] = j;
    }
    return pi;
}

void solve()
{
    string s; cin>>s; 
    vector<int>pi = calcular_pi(s);
    /*for(auto x:pi)
        cout<<x<<" ";
    cout<<endl;*/

vector<int>ans;
    int i=pi[s.size()-1];
    while(i>0)
    {
        ans.push_back(i);
        i=pi[i-1];
    }
    sort(ans.begin(), ans.end());

    for(auto x:ans)
        cout<<x<<" ";
    cout<<endl;
}   
 
int main() {ios::sync_with_stdio(false);cin.tie(nullptr);
    int t=1; //cin>>t;
    while(t--)//cin>>t && t!=0)
    {
        //cout<<"Printing order for "<<t<<" pages:\n";
        solve();
    }
}
