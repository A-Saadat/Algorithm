#include <bits/stdc++.h> 
using namespace std; 

#define def 10000000 
#define forn(i,k,n) for(int i=k;i<n;i++) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define msi map<string, int> 
#define mci map<char, int> 
#define si set<int> 
#define pb push_back 
#define F first 
#define S second 
#define mp make_pair 
#define elif else if 
typedef long long int ll; 
typedef int64_t i64; 
typedef vector<ll> vci;
typedef pair<int,int> pii; 
typedef vector<pii> vpii; 
typedef vector<string> vs; 
typedef vector<bool> vb; 
typedef vector<double> vd; 
typedef vector<char> vcc; 

const ll LIMIT = 1e8; 

vci ans;
vcc a(def);

char Alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int main (void)
{
    ll t; cin >> t;

    while(t--){
        a.clear(); ans.clear();
        ll n; cin >> n;

        forn(i,0,n) cin >> a[i];

        forn(i,0,n){
            if(i + 2 < n and a[i] != '0'){
                if(a[i + 2] == '0'){
                    ll x = (a[i] - 48) * 10 + (a[i + 1] - 48);
                    ans.pb(x);
                    i += 2;
                }

            }


            if(a[i + 2] != '0' && a[i] != '0'){
                ans.pb(a[i] - 48);
            }
        }

        forn(i,0,ans.size()) cout << Alphabet[ans[i] - 1];
        cout << endl;
    }
}