#include <bits/stdc++.h> 
using namespace std; 

#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define pb push_back 
#define elif else if 
#define F first 
#define S second 
#define all(v) v.begin(), v.end() 
#define uni(v) sort(all(v)), v.erase(unique(all(v)), v.end()) 
#define err_par(i, j) cout << "par[" << i << "][" << (1 << j) << "] = " << par[i][j] << endl;
#define int long long 
typedef vector<int> vi;

const int MAX = 1e6; 
const int INF = 1e9 + 7; 

vector<int> adj[MAX], red; 
int hig[MAX], hig2[MAX], mark[MAX];
int par[MAX][30];
int n, q;
bool isOk = 1;
int sq = 2;

inline int LCA(int v, int u){ // ? bug
    if(hig[u] < hig[v]) swap(v, u);
    if(v == 1 || u == 1) return 1;

    for(int i = 22; i >= 0; i--){
        int x = par[u][i];
        if(hig[x] >= hig[v]) u = x;
    }

    if(u == v) return u;

    for(int i = 22; i >= 0; i--){
        if(par[u][i] != par[v][i]){
            v = par[v][i];
            u = par[u][i];
        }
    }

    return par[u][0];
}

void dfs(int v, int p){
    par[v][0] = p;
    for(int i = 1; i <= 22; i++)
        par[v][i] = par[ par[v][i - 1] ][i - 1];

    for(int u: adj[v]){
        if(u == p) continue;

        hig[u] = hig[v] + 1;
        dfs(u, v);
    }   
}

inline void MS_BFS(){
    queue<int> q;
    for(int u: red){
        q.push(u);
        mark[u] = 1;
        hig2[u] = 0;
    } 

    memset(mark, 0, sizeof(mark));

    while(!q.empty()){
        int fr = q.front(); mark[fr] = 1; q.pop();
        for(int u: adj[fr]){
            if(mark[u]) continue;
            
            q.push(u);
            hig2[u] = hig2[fr] + 1;
        }
    }
}

inline int get(int v){
    cout << "the state of isOk = " << isOk << endl;
    if(isOk == 1) return hig2[v];

    int ans = INF;
    for(int u: red){
        int x = hig[v] + hig[u] - LCA(v, u);
        cout << u << ": " << x << endl;
        ans = min(ans, x);
    }
}


main()
{IOS;

    cin >> n >> q;
    for(int i = 1; i < n; i++) {
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    dfs(1, 0);

    red.pb(1);
    MS_BFS();

    for(int i = 1; i <= q; i++){
        if( !(i % sq) ){
            MS_BFS();
            isOk = 1; // ? isOk = 1 means that we can use the MS_BFS for finding the heights
        }

        int type; cin >> type; 
        if(type == 1) {
            int l; cin >> l;
            red.pb(l);
            isOk = 0;
        }
        else{
            int v; cin >> v;
            // cout << "ans: " << get(v) << endl;
        }
            
        cout << "i = " << i << " || isOk = " << isOk << " and red nodes are:\n";
        for(int u: red) cout << u << " ";
        cout << "\n---------------------------------\n";  
    }

}