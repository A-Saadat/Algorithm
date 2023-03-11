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
int mark[MaxN], hig[MaxN], hig2[MaxN], ifc[MaxN]; // ? ifc = infected vertices 
int n, m, d, L, R; // ? L and R, are the farthest Infected vertices
bool Check;

void dfs(int v){
    mark[v] = 1;
    for(int u: adj[v]){
        if(mark[u]) continue;

        hig[u] = hig[v] + 1;
        dfs(u);
    }
}

void Diameter(){
    dfs(1);

    int Hig = 0;
    forn(i,1,n + 1)
        if(hig[i] > Hig && ifc[i]) L = i, Hig = hig[i];

    memset(mark, 0, sizeof(mark));
    memset(hig, 0, sizeof(hig));

    dfs(L);

    int Dia = 0;
    forn(i,1,n + 1)
        if(hig[i] > Dia && ifc[i]) Dia = hig[i], R = i;

}

void bfs(){
    queue<int> q;
    q.push( (!Check ? L : R) );

    while(!q.empty()){
        int h = q.front(); mark[h] = 1;

        for(int u: adj[h]){
            if(mark[u]) continue;

            q.push(u);
            if(!Check) hig[u] = hig[h] + 1;
            else hig2[u] = hig2[h] + 1;
            mark[u] = 1;
        }

        q.pop();

    }

    memset(mark, 0, sizeof(mark));
    Check = 1;

}

main()
{IOS;

    cin >> n >> m >> d;
    forn(i,0,m) {
        int x; cin >> x;
        ifc[x] = 1;
    }
    
    forn(i,1,n){
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    Diameter();
    memset(mark, 0, sizeof(mark)); memset(hig, 0, sizeof(hig));
    bfs(); bfs();

    int ans = 0;
    forn(i,1,n + 1) 
        if(hig[i] <= d && hig2[i] <= d) ans++;

    cout << ans;
}