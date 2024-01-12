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
typedef long long int ll; 
typedef vector<int> vi;

const int MAX = 1e6; 
const ll INF = 1LL * 1000 * 1000 * 1000 * 1000 * 1000 * 1000; 

vector< pair<int, ll> > adj[MAX]; 
set< pair<ll, int> > s;
ll dis[MAX];
int mark[MAX];

main()
{IOS;

    int n, m; cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x, y; ll val; 
        cin >> x >> y >> val;
        adj[x].pb( {y, val} );
        adj[y].pb( {x, val} );
    }

    for(int i = 0; i <= n; i++)
        dis[i] = INF;

    dis[0] = 0;
    s.insert( {dis[0], 0} );

    while(!s.empty()){
        auto itr = s.begin();
        
        ll d = itr->F; // ? the distance of vetix v form root ( i know that it's not a tree :) )
        int v = itr->S;

        s.erase(itr);
        mark[v] = 1;

        for(auto x : adj[v]){
            int u = x.F;
            ll w = x.S;

            if(mark[u]) continue;

            if(dis[u] > d + w){
                s.erase( {dis[u], u} );
                dis[u] = d + w;
                s.insert( {dis[u], u} );
            }
        }
    }

    
}