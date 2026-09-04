#include <bits/stdc++.h>
using namespace std;

const int MAX_NODES = 1000005; 
const int ALPHABET_SIZE = 26; 
const long long MOD = 1e9+7;

struct Node {
    int next[ALPHABET_SIZE];
    int word_count; 

    Node() {
        fill(next, next + ALPHABET_SIZE, 0);
        word_count = 0;
    }
};

Node trie[MAX_NODES];
int node_count = 0;

void insert(const string& s) {
    int u=0;
    for(char c:s) {
        int idx = c - 'a';
        if (trie[u].next[idx] == 0) {
            trie[++node_count] = Node();
            trie[u].next[idx] = node_count;
        }
        u = trie[u].next[idx];
    }
    trie[u].word_count++;
}

void solve()
{
    string s; cin>>s; 
    int n=s.size();
    int k; cin>>k; 
    vector<string> arr(k);
    for(int i=0; i<k; i++)
    {
        string s2; cin>>s2; 
        insert(s2);
    }

    vector<long long> dp(n+1, 0);
    dp[0]=1;
    int post=0;

    for(int i=0; i<n; i++)
    {
        post=0;
        for(int j=i; j<n; j++)
        {
            if(trie[post].next[s[j]-'a']==0) //si no existe camino
            {
                break;
            }
            else // si existe un camino
            {
                //cout<<s[j]<<endl;

                post=trie[post].next[s[j]-'a'];
                if(trie[post].word_count>0)
                {
                    dp[j+1]=(dp[j+1]+dp[i]) % MOD;
                    //cout<<dp[i]<<" "<<dp[j]<<" fin palabra\n";
                    //post=0;
                }
            }
        }
        //post=0;  
    }

    /*for(auto x: dp)
    {
        cout<<x<<" ";
    }*/


    cout<<dp[n]<<endl;



    
}   
 
int main() {ios::sync_with_stdio(false);cin.tie(nullptr);
    int t=1; //cin>>t;
    while(t--)//cin>>t && t!=0)
    {
        //cout<<"Printing order for "<<t<<" pages:\n";
        solve();
    }
}
