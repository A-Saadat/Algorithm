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

const int MAX = 1e6; 
const int INF = 1e9 + 7; 

vector<int> adj[MAX]; 
vector<int> flr[MAX];
int par[MAX][30], mark[MAX], hig[MAX];
int str[MAX], fin[MAX];

int t = 0;
void dfs(int v){
    ++t; mark[v] = 1; str[v] = t;
    for(int i = 1; i <= 20; i++) par[v][i] = par[ par[v][i - 1] ][i - 1];

    int hh = hig[v];
    flr[hh].pb(v);

    for(int u: adj[v]){
        if(mark[u]) continue;

        hig[u] = hig[v] + 1;
        par[u][0] = v;
        dfs(u);
    }

    fin[v] = t;
}

int Solve(int v, int p){
    int h = 0, hh = hig[v]; // ? h = height of the p-th ancestor of v 
    if(hig[v] - p >= 0) h = hig[v] - p;
    else return 0;

    for(int k = 20; k >= 0; k--){ // ? Binary Lifting
        int x = par[v][k]; 
        if(hig[x] >= h && x > 0) v = x;

    }

    int anc = v; // ? the number of p-th ancester of v

    int curr_flr = flr[hh].size(); // ? the flr that we have to search for that sun of b**chs cousins 

    int L = -1, R = curr_flr - 1;
    while(R - L > 1){
        int mid = (R + L) / 2;
        int u = flr[hh][mid];

        if(str[u] < str[anc]) L = mid;
        else R = mid;
    }

    int st = R;

    L = 0, R = curr_flr;
    while(R - L > 1){
        int mid = (R + L) / 2;
        int u = flr[hh][mid];

        if(fin[u] > fin[anc]) R = mid;
        else L = mid;
    }

    int fn = L;

    return fn - st;
}

main()
{IOS;

    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        if(!x) continue;

        adj[x].pb(i);
        adj[i].pb(x);
    }

    for(int i = 1; i <= n; i++){
        if(mark[i]) continue;


        dfs(i);
    }

    int q; cin >> q;
    while(q--){
        int vi, pi; cin >> vi >> pi;
        cout << Solve(vi, pi) << ' ';
    }
}