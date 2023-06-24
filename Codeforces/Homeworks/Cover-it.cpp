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

vector<int> adj[MaxN], c1, c2; 
map<int, int> mark, col;
int n, m;

void clearArr(){
    forn(i,1,n + 1) adj[i].clear();
    mark.clear(), col.clear();
    c1.clear(), c2.clear();
}

// inline void bfs(){
//     queue<int> q;
//     q.push(1);
//     col[1] = 1;
//     c1.pb(1);

//     while(!q.empty()){
//         int h = q.front(); mark[h] = 1;

//         for(int u: adj[h]){
//             if(mark[u]) continue;

//             col[u] = 3 - col[h];

//             if(col[u] == 1) c1.pb(u);
//             else c2.pb(u);

//             mark[u] = 1;
//             q.push(u);
//         }

//         q.pop();
//     }
// }

void dfs(int v){
    mark[v] = 1;
    for(int u: adj[v]){
        if(mark[u]) continue;

        col[u] = 3 - col[v];
        if(col[u] == 1) c1.pb(u);
        else c2.pb(u);

        dfs(u);
    }
}

main()
{IOS;

    int t; cin >> t;
    while(t--){
        cin >> n >> m;
        clearArr();
        forn(i,0,m) {
            int x, y; cin >> x >> y;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        
        col[1] = 1;
        c1.pb(1);
        dfs(1);
        
        if(c1.size() <= c2.size()) {
            cout << c1.size() << endl;
            for(int u: c1) cout << u << ' ';
        }
        else{
            cout << c2.size() << endl;
            for(int u: c2) cout << u << ' ';
        }
        

        cout << endl;
    }    

}