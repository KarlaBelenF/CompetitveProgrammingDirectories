#include <bits/stdc++.h>
using namespace std;
using ll = __int128; // Si se usa long long, usar 2 hashes
const int MAX_LEN = 2e6 + 5;  // Ajustar para N
const ll MOD = (1LL << 61) - 1, P = 31; // P >= alfabeto
ll pw[MAX_LEN], pw_inv[MAX_LEN], h[MAX_LEN];

ll power(ll b, ll e) { // exp binaria
    ll r = 1; b %= MOD;
    while (e) {
        if (e & 1) r = r * b % MOD;
        b = b * b % MOD;
        e >>= 1;
    }
    return r;
}

void h_precompute() { // precalcula potencias del primo
    pw_inv[0] = pw[0] = 1;
    ll inv = power(P, MOD - 2);
    for(int i=1; i<MAX_LEN; i++){
        pw[i] = pw[i-1] * P % MOD;
        pw_inv[i] = pw_inv[i-1] * inv % MOD;
    }
}

void h_build(string& s) { // construye prefix-hash
    h[0] = 0;
    for(int i=0; i<s.size(); i++){
        h[i+1] = (h[i] + (ll)(s[i]-'a'+1) * pw[i]) % MOD;
    }
}

ll get_hsh(int l, int r) { // hash de s[l..r]
    return (h[r+1] - h[l] + MOD) % MOD * pw_inv[l] % MOD;
}

void solve()
{
    string s; cin>>s; 
    int n=s.size();
    h_build(s);
    for(int i=1; i<n; i++)
    {
        ll hash1 = get_hsh(0,i-1);
        ll hash2 = get_hsh(n-i, n-1);
        if(hash1==hash2)
            cout<<i<<" ";
        /*else
            cout<<(long long)hash1<<" "<<(long long)hash2<<endl;*/
    }

}   
 
int main() {ios::sync_with_stdio(false);cin.tie(nullptr);
    int t=1; //cin>>t;
    h_precompute();
    while(t--)//cin>>t && t!=0)
    {
        //cout<<"Printing order for "<<t<<" pages:\n";
        solve();
    }
}
