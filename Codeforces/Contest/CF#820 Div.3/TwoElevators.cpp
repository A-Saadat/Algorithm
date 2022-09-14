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

int main (void)
{
    ll t; cin >> t;
    while(t--){
        ll a, b, c; cin >> a >> b >> c;

        ll x = abs(a - 1); ll y = abs(b - c) + abs(c - 1);

        if(x < y) cout << 1 << endl;
        elif(x > y) cout << 2 << endl;
        else cout << 3 << endl;
    }
}