#include <bits/stdc++.h>
#include <queue>
using namespace std;
int c,s;
vector<pair<long long, vector<long long>>>reminders;

vector<long long> residact;
priority_queue<long long, vector<long long>, greater<long long>> pq;

long long M=1;

long long extgcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    long long x1, y1;
    long long d = extgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

long long modInverse(long long a, long long m) {
    long long x, y;
    extgcd(a, m, x, y);
    return (x % m + m) % m; 
}



long long crt(const vector<long long>& residuos, const vector<long long>& modulos) {
   // long long M=1; //producto total
    long long ans=0;
    int n=residuos.size();

    

    //construimos los bloques
    for (int i = 0; i < n; i++) {
        long long Mi = M / modulos[i]; //capa de invisibilidad
        long long inv = modInverse(Mi, modulos[i]); //ajustador

        long long term = (long long)(((__int128)residuos[i] * Mi) % M);
        term=(long long)(((__int128)term * inv) % M);
        
        ans=(ans + term) % M;
    }

    long long res=(ans % M + M) % M;
    if(res==0) return M;
    return res;
}

void backtracking(int idx, vector<long long>& modulos)
{
    if(idx==c)
    {
        pq.push(crt(residact,modulos));
        return;
    }

    for(int i=0; i<reminders[idx].second.size(); i++)
    {
        residact.push_back(reminders[idx].second[i]);
        backtracking(idx+1,modulos);
        residact.pop_back();
    }
    
}



void solve()
{
    long long x,k; 
    
    long long possol=1;

    for(int j=0; j<c; j++)
    {
        cin>>x>>k;
        reminders.push_back({x,vector<long long>()});
        for(int i=0; i<k; i++)
        {
            long long rem; cin>>rem; //ans%x=rem (posible)
            reminders[j].second.push_back(rem);
        }
        sort(reminders[j].second.begin(), reminders[j].second.end());
        possol*=k;
    }
    sort(reminders.rbegin(), reminders.rend());

    if(possol>=10000)
    {
        for(long long mult=0;; mult++)
        {
            for(int i=0; i<reminders[0].second.size(); i++)
            {
                long long candidato=reminders[0].first*mult+reminders[0].second[i];
                //cout<<candidato<<" "<<reminders[0].second[i]<<endl;
                if(candidato==0)continue;
                bool posible=true;
                for(int j=1; j<reminders.size(); j++)
                {
                    long long x=reminders[j].first;
                    bool flag=false;
                    for(int f=0; f<reminders[j].second.size(); f++)
                    {
                        long long y=reminders[j].second[f];
                        if(candidato%x==y)
                        {
                            flag=true;
                            break;
                        }
                    }
                    if(!flag)
                    {
                        posible=false;
                        break;
                    }
                }
                if(posible)
                {
                    cout<<candidato<<"\n";
                    s--;
                    if(s==0)
                        return;
                }
            }
        }
    }
    else
    {
        residact.clear();
        vector<long long> modulos;
        for(int i=0; i<c; i++)
        {
            modulos.push_back(reminders[i].first);
        } 
        for(int i=0; i<c; i++)
        {
            M*=modulos[i];
        }
        backtracking(0,modulos);
        
        while(s!=0)
        {
            s--;
            cout<<pq.top()<<endl;
            pq.push(pq.top()+M);
            pq.pop();
        }

    }
    
    

}
 
int main() {ios::sync_with_stdio(false);cin.tie(nullptr);
    
    while(cin>>c>>s && !(c==0 && s==0))
    {
        reminders.clear();
        M=1;
        
        pq=priority_queue<long long, vector<long long>, greater<long long>>();
        solve();
        cout<<endl;
    }
}
