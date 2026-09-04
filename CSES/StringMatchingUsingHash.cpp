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
    string s1,s2; cin>>s1>>s2; 
    string s=s2+'#'+s1;
    //cout<<s<<endl;
    h_build(s);
    
    int cont=0;
    ll hash2=get_hsh(0,s2.size()-1);
    //cout<<(long long)hash2<<endl;

    for(int i=s2.size()+1; i<=s.size()-s2.size(); i++)
    {
        ll hash1=get_hsh(i,i+s2.size()-1);

        //cout<<(long long)hash1<<endl;

        if(hash1 == hash2)
            cont++;
    }

    cout<<cont<<endl;
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
