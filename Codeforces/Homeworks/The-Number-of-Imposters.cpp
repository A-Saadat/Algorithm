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

const ll MaxN = 2e5 + 10; 
const ll INF = 1e9 + 7; 

int mark[MaxN], col[MaxN]; 
vector< pair<int, int> > adj[MaxN];
vector<int> c[10]; 

// ** Crewmate = 2, Imposter = 1;

bool isOk = true;

void dfs(int v){
    mark[v] = 1;
    for(auto u: adj[v]) {
        if(mark[u.F]){
            //if( (col[u.F] == col[v]) + 1 != u.S) isOk = false;
            if((col[u.F] == col[v]) && u.S == 1) isOk = false;
            elif((col[u.F] != col[v]) && u.S == 2) isOk = false;
            
            continue;
        }

        if(u.S == 1){
            col[ u.F ] = 3 - col[v];
            // cout << v << " " << u.F << ": " << 3 - col[v] << endl;
            c[ (3 - col[v]) ].pb(u.F);
        } 
        else{
            col[ u.F ] = col[v];
            // cout << v << " " << u.F << ": " << col[v] << endl;
            c[ col[v] ].pb(u.F);
        } 

        dfs(u.F);
    }
}

void clearArr(int n){
    forn(i,1,n + 1) adj[i].clear();
    memset(mark, 0, sizeof(mark));
    memset(col, 0, sizeof(col));
}

main()
{IOS;

    int t; cin >> t;
    while(t--){
        isOk = 1;

        int n, m; cin >> n >> m;
        clearArr(n); /// BAD

        forn(i,0,m){
            int x, y; cin >> x >> y;
            string s; cin >> s;

            if(s == "imposter"){
                adj[x].pb( {y, 1} );
                adj[y].pb( {x, 1} );
            }
            else{
                adj[x].pb( {y, 2} );
                adj[y].pb( {x, 2} );   
            }
        }

        int ans = 0;
        forn(i,1,n + 1)
            if(!mark[i]){
                c[1].clear(), c[2].clear();
                col[i] = 1; c[1].pb(i); dfs(i);
                ans += max(c[1].size(), c[2].size());
            } 

        if(!isOk) cout << "-1\n";
        else cout << ans << endl;

    }
}