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

const int MAX = 2e5 + 100; 
const int INF = 1e9 + 7; 

vector<int> adj[MAX];
set< pair<int, int> > E;
int w[MAX], mark[MAX];
int n, m; 
bool isOk;

inline bool Solve(int A){
    int cnt = 1; E.clear(); mark[A] = A;

    for(int u: adj[A])
        E.insert( {w[u], u} );

    while(!E.empty()){
        auto itr = E.begin();
        int v = itr->S;
        int val = itr->F;

        if(val > cnt) return 0;

        E.erase(itr); cnt++; mark[v] = A;
        for(int u: adj[v]){
            if(mark[u] == A) continue;

            E.insert( {w[u], u} );
        }
    }

    return (cnt == n);
}

inline void clear_Arr(){
    isOk = 0;
    for(int i = 1; i <= MAX; i++) adj[i].clear();
    for(int i = 1; i <= MAX; i++) mark[i] = 0;
    E.clear();
}

main()
{IOS;

    int t; cin >> t;
    while(t--){
        clear_Arr();
        cin >> n >> m;
        for(int i = 1; i <= n; i++) cin >> w[i];
        for(int _ = 1; _ <= m; _++) {
            int x, y; cin >> x >> y;
            adj[x].pb(y);
            adj[y].pb(x);
        }

        for(int i = 1; i <= n; i++){
            if(mark[i] || w[i]) continue;

            if(Solve(i)){
                isOk = 1;
                break;
            }
        }

        if(isOk) puts("YES");
        else puts("NO");
    }

}