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

const int MaxN = 1e3; 
const ll INF = 1e9 + 7; 

vector<int> adj[MaxN], ans; 
pair<int, int> edg[MaxN];
int mark[MaxN], G_mark[MaxN], hig[MaxN], n, maxSum;
vector< pair<int, int> > a;

vector< pair<int, int> > remove_edge( pair<int, int> e ){
    int x = e.F, y = e.S;
    vector< pair<int, int> > z;

    int idx1 = 0, idx2 = 0;
    int val1 = 0, val2 = 0;

    for(int i = 0; i < adj[x].size(); i++){

        ll u = adj[x][i];
        if(u == y) {
            idx1 = i; val1 = u;
            adj[x][i] = -1;
            break;
        }

    }

    for(int i = 0; i < adj[y].size(); i++){

        ll u = adj[y][i];
        if(u == x) {
            idx2 = i; val2 = u;
            adj[y][i] = -1;
            break;
        }

    }

    z.pb( {idx1, val1} ); 
    z.pb( {idx2, val2} ); 

    return z;
}

void repair_edge( int idx1, int val1, int idx2, int val2, int x, int y ){
    adj[x][idx1] = val1;
    adj[y][idx2] = val2;
}

void dfs(int v){
    if(v == -1) return;
    
    G_mark[v] = 1;
    mark[v] = 1;

    for(int u: adj[v]){
        
        if(!mark[u] && u != -1) {
            hig[u] = hig[v] + 1;
            dfs(u);
        }
    }
}

int Diameter(int root){
    // * Find the Furthest leaf
    dfs(root);

    int Hig = 0, L = -1;
    forn(i,1,n + 1){
        if(Hig < hig[i]) Hig = hig[i], L = i;
    }

    if(L == -1) return 0;

    memset(mark, 0, sizeof(mark));
    memset(hig, 0, sizeof(hig));

    dfs(L);

    int Diameteri = 0;
    forn(i,1,n + 1) Diameteri = max(Diameteri, hig[i]);

    memset(mark, 0, sizeof(mark));
    memset(hig, 0, sizeof(hig));

    return Diameteri;
}

main()
{IOS;

    cin >> n;
    forn(i,1,n){
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);

        edg[i] = {x, y};
    }

    forn(i,1,n){
        a = remove_edge( edg[i] );
        ans.clear();
        forn(j, 1, n + 1) {
            if(!G_mark[j]) ans.pb(Diameter(j));
        }

        int sum = ans[0] * ans[1];
        maxSum = max(maxSum, sum);

        memset(mark, 0, sizeof(mark)); memset(hig, 0, sizeof(hig)); memset(G_mark, 0, sizeof(G_mark));
        repair_edge(a[0].F, a[0].S, a[1].F, a[1].S, edg[i].F, edg[i].S);
    }

    cout << maxSum << endl;
}