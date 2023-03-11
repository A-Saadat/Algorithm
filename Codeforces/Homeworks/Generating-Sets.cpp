// 57 54 46 
#include <bits/stdc++.h> 
using namespace std; 

#define forn(i,k,n) for(int i = k; i < n; i++) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0); 
#define pb push_back 
#define F first 
#define S second 
#define mp make_pair 
#define gcd __gcd 
#define bp __builtin_popcount 
#define elif else if 
#define all(v) v.begin(), v.end() 
#define uni(v) sort(all(v)), v.erase(unique(all(v)), v.end()) 
#define err(x) cout << '#' << x << ':' << ' ' << x << endl 
typedef long long int ll; 
typedef map<ll, ll> mll; 
typedef set<int> si;  
typedef pair<ll,ll> pii; 
typedef vector<ll> vci;
typedef vector<pii> vpii; 
typedef vector<string> vs; 
typedef vector<char> vcc; 

const ll MaxN = 1e6; 
const ll INF = 1e9 + 7; 

set<int> s;

main()
{IOS;

    int n; cin >> n;
    forn(i,0,n){
        int x; cin >> x;
        s.insert(x);
    }
    
    while(true){
        int x = *s.rbegin(); 
        auto itr = s.rbegin();

        while(s.count(x)) x /= 2;
        if(!x) break;

        s.erase(*itr);
        s.insert(x);
    }

    fort(itr, s) cout << *itr << ' ';

}