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
#define int long long 

const int MAX = 1e5 + 10; 
const int INF = 1e9 + 7; 

vector<pair<int, int>> adj[MAX][3];
vector<int> door[MAX];
int a[MAX], cmp[MAX][3], mark[MAX][3];
int now = 0;

void Add(int x, int y, int s1, int s2){
    adj[x][s1].pb( {y, s2} );
    adj[y][s2].pb( {x, s1} );
}

void dfs(int v, int st){
    cmp[v][st] = now; mark[v][st] = 1;
    for(auto u: adj[v][st]) if(!mark[u.F][u.S]) dfs(u.F, u.S);
}

main()
{IOS;

    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++){
        int cnt; cin >> cnt;
        while(cnt--){
            int x; cin >> x;
            door[x].pb(i);
        }
    }

    for(int i = 1; i <= n; i++){
        int x = door[i][0], y = door[i][1];
        if(a[i] == 1){
            Add(x, y, 1, 1); // ? 1 = reverse
            Add(x, y, 0, 0); // ? 0 = original
        }
        else{
            Add(x, y, 0, 1);
            Add(x, y, 1, 0);
        }
    }

    for(int i = 1; i <= m; i++){
        if(!mark[i][0]) now++, dfs(i, 0);
        if(!mark[i][1]) now++, dfs(i, 1);
    }

    bool isOk = 1;
    for(int i = 1; i <= m; i++)
        if(cmp[i][0] == cmp[i][1]) isOk = 0;

    if(isOk) cout << "YES\n";
    else cout << "NO\n";

}