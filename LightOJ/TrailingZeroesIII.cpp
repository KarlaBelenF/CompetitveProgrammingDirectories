#include <bits/stdc++.h>
using namespace std;

vector<long long> pot5;

long long ceros(long long n)
{
    long long cant=0;
    for(int i=0; i<pot5.size(); i++)
        cant+=(n/pot5[i]);
    return cant;
}

void solve()
{
    /*unsigned long long fact=1;
    for(int i=1; i<100; i++)
    {
        fact*=i;
        cout<<fact<<endl;
    }*/

    unsigned long long n,ans=-1,l=0,r=1e18,m;
    cin>>n; 

    while(l<=r)
    {
        m=(l+r)/2;
        
        long long numceros=ceros(m);
        //cout<<l<<" "<<m<<" "<<r<<" "<<numceros<<" "<<ans<<endl;
        if(numceros<n)
        {
            l=m+1;
        }
        else
        {
            ans=min(ans,m);
            r=m-1;
        }
            
    }

    if(ans==-1 || ceros(ans)!=n)
        cout<<"impossible\n";
    else
        cout<<ans<<endl;
    


}
 
int main() {ios::sync_with_stdio(false);cin.tie(nullptr);
    int t=1; 
    pot5.push_back(5);
    for(int i=1; i<=100; i++)
        pot5.push_back(pot5[pot5.size()-1]*5);
    cin>>t; 
    int origt=t;
    while(t--)
    {
        cout<<"Case "<<origt-t<<": ";
        solve();
    }
        
    return 0;
}
