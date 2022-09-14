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
char a[def];
msi req;

vcc t;

int main (void)
{
    ll n; cin >> n;
    forn(i,0,n) cin >> a[i];

    forn(i,0,n){
        if(i + 1 < n){
            t.clear();
            t.pb(a[i]); t.pb(a[i + 1]);

            string s; s.clear();
            forn(i,0,t.size()) s += t[i];

            if(req.find(s) == req.end()) req[s] = 0;
            req[s]++;
        }
    }

    string ans; ll max = 0;
    fort(itr,req){
        if(itr->S > max) { ans = itr->F; max = itr->S; }
    };

    cout << ans;
}