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

vector<int> adj[MaxN], tmp, v; 
int mark[MaxN], hig[MaxN], par[MaxN], mark_2[MaxN];
int n, L, R;
queue<int> q;

void dfs(int v){
    mark[v] = 1;
    for(auto u: adj[v])
        if(!mark[u]){
            hig[u] = hig[v] + 1;
            par[u] = v;
            dfs(u);
        }
}

int Diameter(){
    // * Find the Furthest leaf
    int HIG = 0;
    dfs(1);
    forn(i,1,n + 1) 
        if(HIG < hig[i]) L = i, HIG = hig[i];

    memset(mark, 0, sizeof(mark));
    memset(hig, 0, sizeof(hig));
    memset(par, 0, sizeof(par));

    dfs(L);
    int Dia = 0;
    forn(i,1,n + 1)
        if(Dia < hig[i]) R = i, Dia = hig[i];

    tmp.pb(R);
    tmp.pb(L);

    return Dia;
}

void bfs(){

    while(!q.empty()){
        int h = q.front(); mark[h] = 1;

        for(int u: adj[h]){
            if(mark[u]) continue;

            q.push(u);
            mark[u] = 1;

            hig[u] = hig[h] + 1;
        }

        q.pop();

    }

}

main()
{IOS;

    cin >> n;
    forn(i,1,n){
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    int Dia = Diameter();

    memset(mark, 0, sizeof(mark)); memset(hig, 0, sizeof(hig));

    q.push(L);
    mark_2[L] = 1;

    int curr = R, cnt = 0;
    while(curr != L){
        // cout << curr << ' '; 

        q.push(curr);
        curr = par[curr];
        mark[curr] = 1;
        mark_2[curr] = 1;
        cnt++;

    }


    bfs();
    
    int Hig = 0, t = -1;
    forn(i,1, n + 1) {
        if(Hig <= hig[i] && i != L && i != R) Hig = hig[i], t = i;
    }
    
    cout << hig[t] + cnt << endl;
    cout << L << ' ' << R << ' ' << t;
    

}