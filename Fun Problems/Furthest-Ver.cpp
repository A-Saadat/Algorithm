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

const ll MaxN = 1e6; 
const ll INF = 1e9 + 7; 

vector<int> adj[MaxN]; 
int maxSub[MaxN], maxUnSub[MaxN], ver[MaxN];

void dfs_1(int v, int par){
    for(int u: adj[v]){
        if(u != par){
            dfs_1(u, v);

            if( (maxSub[u] + 1) > maxSub[v] ){
                ver[v] = u;
                maxSub[v] = maxSub[u] + 1;
            }
        }
    }
}

void dfs_2(int v, int par){
    int mx = 0;
    for(int u: adj[v]){
        if(u != par && u != ver[v]){
            maxUnSub[u] = max(maxSub[v] + 1, maxUnSub[v] + 1);

            dfs_2(u, v);
            mx = max(mx, maxSub[u]);
            
        } 
        else
            maxUnSub[u] = max(maxSub[v] + 1, mx + 2);
    }
}

main()
{IOS;

    int n; cin >> n;
    forn(i,1,n){
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    dfs_1(1, 1); // ** to Find the Furthest Vertix from any Vertices in it's subTree

    dfs_2(1, 1); // ** to Find the Furthest Vertix from any Vertices that it's NOT in it's subTree

    forn(i,1,n + 1){
        cout << i << ": " << maxSub[i] << ", " << maxUnSub[i] << endl;
    }
}