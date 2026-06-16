#include <bits/stdc++.h>
using namespace std;
vector<int> tot(1e6+5);
vector<long long> sumgcd(1e6+5);
vector<long long> ans(1e6+5);

void precomputeTotient()
{
    for(int i=0; i<tot.size(); i++)
        tot[i]=i;

    for(int i=2; i<tot.size(); i++)
    {
        if(tot[i]==i)
        {
            for(int j=i; j<tot.size(); j+=i)
            {
                tot[j]=tot[j]-tot[j]/i;
            }
        }
    }
}

void solve()
{
    
   /* long long  G = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i+1; j <= n; j++) 
        {
            G += gcd(i, j);
            //cout<<"i="<<i<<" j="<<j<<" gcd= "<<gcd(i,j)<<" G="<<G<<endl;
        }
    }

    // G=suma de gcds de todas las parejas (i,j) hasta n con i!=j
    //cout<<G<<endl;*/

    for(int j=1; j<1e6+5; j++)
    {
        for(int i=j+j; i<1e6+5; i+=j)
        {
            sumgcd[i]=sumgcd[i]+(long long)j*tot[i/j];
        }
    }
    
    for(int i=1; i<sumgcd.size(); i++)
    {
        ans[i]=ans[i-1]+sumgcd[i];
    }
       

    

}
 
int main() {ios::sync_with_stdio(false);cin.tie(nullptr);
    int n;
    precomputeTotient();
    solve();
    while(cin>>n && n!=0)
    {
            cout<<ans[n]<<endl;
    }
}
