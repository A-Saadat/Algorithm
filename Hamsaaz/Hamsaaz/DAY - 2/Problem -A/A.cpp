#include <bits/stdc++.h> 
using namespace std; 

#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0) 
#define forn(i,k,n) for(int i = k; i < n; i++) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define pb push_back 
#define elif else if 
#define F first 
#define S second 
#define gcd __gcd 
#define all(v) v.begin(), v.end() 
#define uni(v) sort(all(v)), v.erase(unique(all(v)), v.end()) 
#define err(x) cout << '#' << x << ':' << ' ' << x << endl 
typedef long long int ll; 
typedef vector<int> vi;

const int MaxN = 1e6; 
const int MOD = 1e9 + 7; 

int a[MaxN]; 
vector<int> adj[MaxN];

main()
{IOS;

    freopen("inputa.txt", "r", stdin);

    int n = 5 * 1e4;
    for(int i = 0; i < n; i++) cin >> a[i];
    
    for(int i = 1; i < n; i++){
        int x, y; cin >> x >> y;

        adj[x].pb(y);
        adj[y].pb(x);
    }

    for(int i = n - 1; i >= 0; i--){
        cout << i << ": ";
        for(int u: adj[i]) cout << u << ' ';
        cout << "\n-------------\n";
    }


}