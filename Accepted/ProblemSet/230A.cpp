#include <bits/stdc++.h> 
using namespace std; 

#define def 10000000 
#define forn(i,n) for(int i=0;i<n;i++) 
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
typedef vector<ll> vci;
typedef pair<int,int> pii; 
typedef vector<pii> vpii; 
typedef vector<string> vs; 
typedef vector<bool> vb; 
typedef vector<double> vd; 

vpii a;

int main (void)
{
    ll s, n; cin >> s >> n;

    forn(i,n){
        ll x, y; cin >> x >> y;
        a.pb(mp(x,y));
    }

    sort(a.begin(), a.end());

    forn(i,n){
        if(s < a[i].F or s <= 0 or s - a[i].F <= 0){
            cout << "NO";
            return 0;
        }
        s += a[i].S;
        
    }

    cout << "YES";
}