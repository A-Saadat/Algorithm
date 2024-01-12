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
const int INF = 1e9 + 7; 

vector<int> adj[MAX], comp[MAX];
int cc[MAX], dia[MAX];
int mark[MAX], hig[MAX];
int n, m, q, col;

inline int f(int u){
    if(u % 2) return ((u / 2) + 1);
    else return u / 2;
}

void dfs_1(int v){
    cc[v] = col;
    comp[col].pb(v);
    for(int u: adj[v]){
        if(cc[u]) continue;
        dfs_1(u);
    }
}

void dfs_2(int v){
    mark[v] = 1;
    for(int u: adj[v]){
        if(mark[u]) continue;

        hig[u] = hig[v] + 1;
        dfs_2(u);
    }
}

inline int Find_Dia(int v){
    for(int u: comp[ cc[v] ]){
        mark[u] = 0;
        hig[u] = 0;
    } 

    dfs_2(v);
    int dd = 0, maxi = 0;
    for(int u: comp[ cc[v] ]) {
        if(hig[u] >= maxi){
            dd = u;
            maxi = hig[u];
        } 
    }

    for(int u: comp[ cc[v] ]){
        mark[u] = 0;
        hig[u] = 0;
    }

    dfs_2(dd);

    maxi = 0;
    for(int u: comp[ cc[v] ])
        maxi = max(maxi, hig[u]);

    return maxi;
}

inline void merge(int A, int B){
    A = cc[A];
    B = cc[B];

    if(A == B) return;

    if(comp[A].size() > comp[B].size()) swap(A, B);

    for(int u: comp[A]){
        cc[u] = B;
        comp[B].pb(u);
    }

    comp[A].clear();

    int d = f(dia[A]) + f(dia[B]) + 1;
    // cout << "?? " << f(dia[A]) << " + " << f(dia[B]) + 1 << endl;
    dia[B] = max(d, max(dia[A], dia[B]));
    dia[A] = 0;
}

main()
{IOS;

    cin >> n >> m >> q;
    for(int i  = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    for(int i = 1; i <= n; i++){
        if(cc[i]) continue;

        ++col;
        dfs_1(i);
    }

    for(int i = 1; i <= n; i++) {
        if(mark[i]) continue;

        dia[ cc[i] ] = Find_Dia(i);
    }

    // for(int i = 1; i <= col; i++) cout << "dia[" << i << "] = "  << dia[i] << endl;

    while(q--){
        int t; cin >> t;
        if(t == 1){
            int u; cin >> u;
            cout << dia[ cc[u] ] << endl;
        } 
        else{
            int u, v; cin >> u >> v;
            merge(u, v);
        }
    }

    // cout << "\n------------------\n";
    // for(int i = 1; i <= col; i++) cout << "dia[" << i << "] = "  << dia[i] << endl;

}

    // for(int i = 1; i <= col; i++){
    //     cout << i << ": ";
    //     for(int u: comp[i]) cout << u << " ";
    //     cout << "\n----------------\n";
    // }
// cout << "\n-------------------\n";
// for(int i = 1; i <= n; i++) cout << i << ": " << cc[i] << endl;