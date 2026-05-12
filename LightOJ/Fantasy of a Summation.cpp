#include <bits/stdc++.h>
using namespace std;

unsigned long long binpow(unsigned long long a, unsigned long long b, unsigned long long m) {
    a %= m;
    unsigned long long res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

void solve()
{
    unsigned long long n,k,MOD;
    cin>>n>>k>>MOD; 
    vector<unsigned long long> arr;

    //cout<<MOD<<endl;

    for(int i=0; i<n; i++)
    {
        unsigned long long x; cin>>x; 
        arr.push_back(x);
    }

    /*int res = 0;
    for(int i1 = 0; i1 < n; i1++ ) {
        for(int i2 = 0; i2 < n; i2++ ) {
            for(int i3 = 0; i3 < n; i3++ ) {
                for(int i4=0 ; i4<n; i4++)
                {
                    res = ( res + arr[i1] + arr[i2] + arr[i3] +arr[i4]) % MOD;
                    cout<<res<<" "<<i1<<" "<<i2<<" "<<i3<<" "<<i4<<" "<<endl;
                }
                
            }
        }
    }

    cout<<res<<endl;*/

    // ( (n^k)/n * arr[i] ) * k;

    unsigned long long ans=0;

    unsigned long long mult = binpow(n,k-1,MOD);// * binpow(n,MOD-2,MOD);

    //cout<<mult<<endl;

    for(int i=0; i<n; i++)
    {
        ans+=(mult*arr[i] % MOD) %MOD;
    }

    ans*=k % MOD;

    ans%=MOD;

    cout<<ans<<endl;
    
}
 
int main() {ios::sync_with_stdio(false);cin.tie(nullptr);
    int t=1; 
    cin>>t; 
    int cont=0;
    while(t--)
    {
        cont++; 
        cout<<"Case "<<cont<<": ";
        solve(); 
    }
        
    return 0;
}