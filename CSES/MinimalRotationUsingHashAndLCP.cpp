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
    s=s+s;
    int n=s.size();
    h_build(s);
    int besti=0;

    for(int i=1; i<n/2; i++)
    {
        //cout<<s.substr(i,n/2)<<endl;
        int l=i, r=i+n/2-1, m, ans=0;
        while(l<=r)
        {
            m=(l+r)/2;
            //if(s.substr(besti,m-i+1) == s.substr(i,m-i+1))
            if(get_hsh(besti,besti+m-i) == get_hsh(i,m))
            {
                ans=m;
                //cout<<"ans "<<l<<" "<<r<<" "<<m<<endl;
                l=m+1;
            }
            else
            {
                //cout<<"bs "<<l<<" "<<r<<" "<<m<<s.substr(besti,m-i+1)<<" "<<s.substr(i,m-i+1)<<endl;
                r=m-1;
            }
        }
        //cout<<ans<<" "<<i<<endl;
        //cout<<"prefijo mas parecido "<<s.substr(besti,max(0,ans-i+1))<<" entre "<<s.substr(besti,n/2)<<" "<<s.substr(i,n/2)<<endl;
        int ipref=max(0,ans-i+1);
        if(s[besti+ipref]>s[i+ipref])
        {
            //cout<<ans<<" "<<s[besti+ans-1]<<" "<<s[i+ans-1]<<" "<<i<<endl;
            besti=i;
            
        }
        else
        {
            //cout<<ans<<" "<<s[besti+ans-1]<<" "<<s[i+ans-1]<<endl;
        }
            
    }
    cout<<s.substr(besti,n/2)<<endl;
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
