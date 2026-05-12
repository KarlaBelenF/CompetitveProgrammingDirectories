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
    long long a,b,ans=1; cin>>a>>b;
    if(b*b>=a)
    {
        cout<<0<<endl;
        return;
    }
    long long origa=a;

    for(int i=0; i<primos.size() && (long long)(primos[i]*primos[i])<= a; i++)
    {
        if(a%primos[i]==0)
        {
            int pot=0;
            while(a%primos[i]==0)
            {
                pot++;
                a/=primos[i];
            }
            ans*=pot+1;
        }
    }

    if(a>1)
        ans*=2;

    a=origa;
    ans/=2;

    for(int i=1; i<b; i++)
    {
        if(a%i==0)
            ans--;
    }

    cout<<ans<<endl;


}
 
int main() {ios::sync_with_stdio(false);cin.tie(nullptr);
    sieve(1e6+5);
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