// 57 54 46 
#include <bits/stdc++.h> 
using namespace std; 

#define forn(i,k,n) for(int i = k; i < n; i++) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0); 
#define pb push_back 
#define F first 
#define S second
#define gcd __gcd 
#define elif else if 
#define all(v) v.begin(), v.end() 
#define uni(v) sort(all(v)), v.erase(unique(all(v)), v.end()) 
#define err(x) cout << '#' << x << ':' << ' ' << x << endl 
typedef long long int ll; 
typedef vector<int> vi;

const ll MaxN = 2e5 + 10; 
const ll INF = 1e9 + 7; 

map<int, int> mp[MaxN]; 
int a[MaxN];

main()
{IOS;

    int n; cin >> n;
    forn(i,1,n) {
        int u, v; cin >> u >> v;
        mp[u][v] = 1;
        mp[v][u] = 1;
    }

    forn(i,0,n) cin >> a[i];

    if(a[0] != 1) { cout << "No" << endl; return 0; }

    int L = 0, R = 1;
    while(L < n && R < n){
        
        while(mp[ a[L] ][ a[R] ]) R++;

        L++;
    }

    if(R == n) cout << "Yes";
    else cout << "No";

}