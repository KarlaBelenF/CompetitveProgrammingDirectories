#include <bits/stdc++.h>
using namespace std;

vector<bool> is_prime;
vector<int>primos;
void sieve(int n) {
    is_prime.assign(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= n; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= n; i += p)
                is_prime[i] = false;
        }
    }
    for(int i=2; i<=n; i++)
    {
        if(is_prime[i])
            primos.push_back(i);
    }
}

void solve()
{
    unsigned long long n,orign,ans=1;
    cin>>n; 
    orign=n;
    for(int i=0; i<primos.size(); i++)
    {
        if(n%primos[i]==0)
        {
            int exp=0; 
            while(n%primos[i]==0)
            {
                exp++;
                n/=primos[i];
            }
            ans*=(exp*2+1);
        }
    }

    if(n>1)
        ans*=3;

    ans/=2;
    ans++;

    n=orign;

   // cout<<pairsFormLCM(n)<<endl;
    cout<<ans<<endl;
    
}
 
int main() {ios::sync_with_stdio(false);cin.tie(nullptr);
    sieve(1e7+5);
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