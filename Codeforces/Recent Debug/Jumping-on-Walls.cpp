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
#define elif else if 
#define all(v) v.begin(), v.end() 
#define uni(v) sort(all(v)), v.erase(unique(all(v)), v.end()) 
#define err(x) cout << '#' << x << ':' << ' ' << x << endl 
typedef long long int ll; 
typedef vector<int> vi;

const ll MaxN = 5e4 + 10; 
const ll INF = 1e9 + 7; 

string a[MaxN];
vector< pair<int, int> > v;



main()
{IOS;

    int n, k; cin >> n >> k;
    forn(i,1,3) cin >> a[i];

    bfs();

    // forn(i,1,3){
    //     if( a[i][n - k + 1] != 'X')
    //         v.pb( {i, n - k + 1} ); 
    //     if( a[i][n - 1] != 'X')
    //         v.pb( {i, n} );
    // }

    // for(auto u: v) cout << u.F << ' ' << u.S << endl;

}