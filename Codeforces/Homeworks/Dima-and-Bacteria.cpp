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
#define err_mat(i, j) cout << "mat[" << i << "][" << j << "] = " << mat[i][j] << endl;
#define err_dis(i, j) cout << "dis[" << i << "][" << j << "] = " << dis[i][j] << endl;
typedef long long int ll; 
typedef vector<int> vi;

const int MAX = 1e6; 
const int MAXK = 5e2 + 100; 
const int INF = 1e9 + 7; 

// ! col = the type of each Bacteria || ldr = the leader of each type 
int ldr[MAXK], sum[MAXK], sz[MAXK];
int col[MAX], mark[MAX], mat[MAXK][MAXK];
int n, m, k;  

vector<int> adj[MAX];
vector< pair<int, int> > adj2[MAXK];
set< pair<ll, int> > s;
ll dis[MAXK][MAXK];

inline void Determine_Bacteria_types(){
    for(int i = 1; i <= k; i++){
        cin >> sz[i];
        ldr[i] = sum[i - 1] + 1;
        sum[i] = sum[i - 1] + sz[i];
        for(int j = ldr[i]; j < ldr[i] + sz[i]; j++) col[j] = i;
    }   
}

void dfs(int v){
    mark[v] = 1;
    for(int u: adj[v]){
        if(mark[u]) continue;

        dfs(u);
    }
}

inline void check(int c){
    for(int i = 1; i <= n; i++){
        if(col[i] == c && !mark[i]) {
            cout << "No\n";
            exit(0);
        } 
    }
}

inline void Dijkstra(int v){
    for(int i = 1; i <= k; i++)
        dis[v][i] = INF;
    
    dis[v][v] = 0;
    s.insert( {dis[v][v], v} );
    while(!s.empty()){
        auto itr = s.begin();
        int vv = itr->S;
        ll d = itr->F;
        s.erase(itr);

        for(auto x: adj2[vv]){
            int u = x.F;
            ll w = x.S;

            if(dis[v][u] > d + w){
                s.erase( {dis[v][u], u} );
                dis[v][u] = d + w;
                s.insert( {dis[v][u], u} );
            }
        }
    }
    
}

main()
{IOS;

    cin >> n >> m >> k;
    Determine_Bacteria_types();

    for(int i = 1; i <= k; i++) // ? fill the matrix array
        for(int j = 1; j <= k; j++){
            if(i == j) continue;
            mat[i][j] = INF;
        } 

    for(int i = 1; i <= m; i++){
        int x, y, val; cin >> x >> y >> val;

        if(col[x] != col[y]){
            mat[ col[x] ][ col[y] ] = min( mat[ col[x] ][ col[y] ] , val);
            mat[ col[y] ][ col[x] ] = mat[ col[x] ][ col[y] ];
        }

        if(val > 0) continue;

        adj[x].pb(y);
        adj[y].pb(x);
    }

    bool isOk = 1; 
    for(int i = 1; i <= k; i++){
        memset(mark, 0, sizeof(mark));
        dfs( ldr[i] );
        check(i);
    }

    for(int i = 1; i <= k; i++){
        for(int j = 1; j <= k; j++){
            if(i == j || mat[i][j] == INF) continue;

            adj2[i].pb( {j, mat[i][j]} );
        }
    }

    for(int i = 1; i <= k; i++) 
        Dijkstra(i);

    cout << "Yes\n";

    for(int i = 1; i <= k; i++){
        for(int j = 1; j <= k; j++) cout << (dis[i][j] < INF ? dis[i][j] : -1) << ' ';
        cout << endl;
    }
}