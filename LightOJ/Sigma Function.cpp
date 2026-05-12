#include <algorithm>
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

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a);
        a = (a * a);
        b >>= 1;
    }
    return res;
}

vector<long long> impares;
void generaimpares()
{
    for(long long i=1; i<1e6+500; i++)
    {
        impares.push_back(i*i);
        impares.push_back(i*i*2);
    }
    sort(impares.begin(), impares.end());

    /*for(auto i: impares)
    {
        cout<<i<<" ";
    }*/
}


void solve()
{
    long long n; cin>>n; 
    long long cantimp = (upper_bound(impares.begin(),impares.end(),n) - impares.begin());
    //cout<<"impares "<<cantimp<<endl;
    cout<<n - cantimp<<"\n";
}
 
int main() {ios::sync_with_stdio(false);cin.tie(nullptr);
    //sieve(1e6+5);
    generaimpares();
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