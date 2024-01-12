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

const int MAX = 2e3 + 100; 
const int INF = 1e9 + 7; 

vector< pair<int, pair<int, int> > > edg;
int par[MAX], sz[MAX];
vector< pair<int, int> > adj[MAX];
int n; 

int dis[MAX][MAX];
int mat[MAX][MAX];
set< pair<int, int> > s;

inline int Find_par(int A){
    if(par[A] == A) return A;

    return par[A] = Find_par( par[A] );
}

inline void merge(int A, int B){
    A = Find_par(A);
    B = Find_par(B);

    if(sz[A] > sz[B]) swap(A, B);

    sz[B] += sz[A];
    par[A] = B;
}

inline void Dijkstra(int A){
    for(int i = 1; i <= n; i++) 
        dis[A][i] = INF;
    
    dis[A][A] = 0;
    s.insert( {dis[A][A], A} );
    while(!s.empty()){
        auto itr = s.begin();
        int v = itr->S;
        ll d = itr->F;
        s.erase(itr);

        for(auto x: adj[v]) {
            int u = x.F;
            ll w = x.S;

            if(dis[A][u] > d + w) {
                s.erase( {dis[A][u], u} );
                dis[A][u] = d + w;
                s.insert( {dis[A][u], u} );
            }
        }
    }
}

main()
{IOS;

    cin >> n;

    bool isOk = 1;
    for(int i = 1; i <= n; i++){
        sz[i] = 1, par[i] = i;

        for(int j = 1; j <= n; j++){
            cin >> mat[i][j];
            if(i == j) continue;
            edg.pb( { mat[i][j], {i, j} } );

            if(mat[i][j] == 0) isOk = false;
        } 
    }

    if(!isOk) {
        cout << "NO\n";
        return 0;
    }

    sort(all(edg));
    int cnt = 0;
    for(auto x: edg){
        if(cnt == n) break;
        int A = x.S.F;
        int B = x.S.S;
        ll val = x.F;

        if(Find_par(A) == Find_par(B)) continue;

        adj[A].pb( {B, val} );
        adj[B].pb( {A, val} );

        merge(A, B);
        cnt++;
    }

    for(int i = 1; i <= n; i++)
        Dijkstra(i);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(dis[i][j] != mat[i][j]){
                cout << "NO\n";
                return 0;
            }
        }
    }

    cout << "YES\n";
            
}