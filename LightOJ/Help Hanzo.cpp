#include <bits/stdc++.h>
using namespace std;

vector<long long> primes;
vector<bool> is_prime;
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
            primes.push_back(i);
    }
}


void solve()
{
    long long l,r;
    cin>>l>>r; 

    /*for(int i=0; i<primes.size(); i++)
    {
        cout<<primes[i]<<" ";
    }*/

    vector<bool> primrang(r-l+1, true);
    
    if(l==1)
        primrang[0]=false;

    for(int i=0; i<primes.size(); i++)
    {
        if(r<primes[i]*primes[i])
            break;

       // cout<<primes[i]<<"\n";

        long long primermult = l/primes[i] * primes[i];

        if(primermult < l)
            primermult+=primes[i];

       // cout<<"primer mult "<<primermult<<endl;

       //if(!is_prime[primermult])
       //     primrang[primermult]=false;

        for(long long j=max(primermult,primes[i]*primes[i]); j<=r; j+=primes[i])
        {
            primrang[j-l]=false;
            //cout<<j<<" no es primo\n";
        }
        
    }

    //cout<<endl;

    long long ans=0;
    for(int i=0; i<primrang.size(); i++)
    {
        if(primrang[i])
        {
            //cout<<i<<" ";
            ans++;
        }
    }
    //cout<<endl;

    cout<<ans<<endl;

   /* for (int p = 2; p * p <= n; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= n; i += p)
                is_prime[i] = false;
        }
    }*/
}
 
int main() {ios::sync_with_stdio(false);cin.tie(nullptr);
    sieve(1e5);
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