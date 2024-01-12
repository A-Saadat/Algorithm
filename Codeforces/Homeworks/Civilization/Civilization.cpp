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

const int MAX = 3e5 + 100; 
const int INF = 1e9 + 7; 

vector<int> adj[MAX]; 
int mark[MAX], sz[MAX], par[MAX], dia[MAX];
int hig[MAX];
int n, m, q, col; 

inline int f(int u){
    if(u % 2) return ((u / 2) + 1);
    else return u / 2;
}

void dfs_1(int v){
    mark[v] = 1; sz[col]++;
    for(int u: adj[v]){
        if(mark[u]) continue;

        par[u] = v;
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
    memset(mark, 0, sizeof(mark));
    memset(hig, 0, sizeof(hig));

    dfs_2(v);
    int dd = 0, maxi = 0;
    for(int i = 1; i <= n; i++) {
        if(hig[i] >= maxi){
            dd = i;
            maxi = hig[i];
        } 
    }

    memset(mark, 0, sizeof(mark));
    memset(hig, 0, sizeof(hig));

    dfs_2(dd);

    maxi = 0;
    for(int i = 1; i <= n; i++)
        maxi = max(maxi, hig[i]);

    return maxi;
}

int Find_par(int v){
    if(par[v] == v) return v;

    return par[v] = Find_par( par[v] );
}

inline void merge(int A, int B){
    A = Find_par(A);
    B = Find_par(B);

    if(A == B) return;

    if(sz[A] > sz[B]) swap(A, B);

    int d = f(dia[A]) + f(dia[B]) + 1;
    int Diameter = max(d, max(dia[A], dia[B]));
    // cout << Diameter << endl;

    // cout << "dia[" << A << "] = " << dia[A] << " and dia[" << B << "] = " << dia[B] << endl;
    // cout << f(dia[A]) << " + " << f(dia[B]) << " + 1 = ";
    // cout << d << endl;

    sz[B] += sz[A];
    par[A] = B;
    dia[B] = Diameter;
}

main()
{IOS;

    cin >> n >> m >> q;
    for(int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    for(int i = 1; i <= n; i++) par[i] = i;

    for(int i = 1; i <= n; i++){
        if(mark[i]) continue;

        col = i;
        dfs_1(i);
    }

    for(int i = 1; i <= n; i++){
        if(par[i] != i) continue;

        dia[i] = Find_Dia(i);
    }

    while(q--){
        int t; cin >> t;
        if(t == 1){
            int u; cin >> u;
            cout << dia[ Find_par(u) ] << endl;
        }
        else{
            int u, v; cin >> u >> v;
            merge(u, v);
        }
    } 

}