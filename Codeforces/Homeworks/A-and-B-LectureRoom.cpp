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
#define err_par(i, j) cout << "par[" << i << "][" << (1 << j) << "] = " << par[i][j] << endl;
typedef long long int ll; 
typedef vector<int> vi;

const int MAX = 1e6; 
const int INF = 1e9 + 7; 

vector<int> adj[MAX]; 
int hig[MAX], sub[MAX], par[MAX][30];
int u, v, n;

void dfs(int v, int p){
    par[v][0] = p;
    for(int i = 1; i <= 22; i++)
        par[v][i] = par[ par[v][i - 1] ][i - 1];

    for(int u: adj[v]){
        if(u == p) continue;
        hig[u] = hig[v] + 1; 
        dfs(u, v);
        sub[v] += sub[u];
    }
    ++sub[v];
}

inline int Find_LCA(int A, int B){
    if(hig[A] < hig[B]) swap(A, B);
    for(int i = 22; i >= 0; i--){
        int x = par[A][i];
        if(x == 0) continue;

        if(hig[x] >= hig[B]) A = x;
    }

    if(A == B) return A;
    else{
        for(int i = 22; i >= 0; i--){
            int x = par[A][i];
            int y = par[B][i];

            if(!x || !y) continue;

            if(x != y)
                A = x, B = y;
        }

        u = A, v = B;

        return par[A][0];
    }
}

inline int Solve(int A, int B, int C){
    if(hig[A] < hig[B]) swap(A, B);
    int pth = hig[A] + hig[B] - (2 * hig[C]);

    int h = hig[A] - (pth / 2);

    for(int i = 22; i >= 0; i--){
        int x = par[A][i];
        if(!x) continue;

        if(hig[x] > h) A = x;
    }

    return sub[ par[A][0] ] - sub[A];
}

main()
{IOS;

    cin >> n;
    for(int i = 1; i < n; i++) {
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(1, 0);

    int q; cin >> q;
    while(q--){
        u = 0, v = 0;
        int A, B; cin >> A >> B;
        int C = Find_LCA(A, B);
        int pth = hig[A] + hig[B] - (2 * hig[C]);

        if(A == B) cout << n << endl;
        elif(pth % 2) cout << 0 << endl;
        elif(hig[A] == hig[B]) cout << n - sub[u] - sub[v] << endl;
        else cout << Solve(A, B, C) << endl;
    }

}