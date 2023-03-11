// 57 54 46 
#include <bits/stdc++.h> 
using namespace std; 

#define forn(i,k,n) for(int i = k; i < n; i++) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0); 
#define pb push_back 
#define F first 
#define S second 
#define mp make_pair 
#define gcd __gcd 
#define bp __builtin_popcount 
#define elif else if 
#define aint(v) v.begin(), v.end() 
#define uni(v) sort(aint(v)), v.erase(unique(aint(v)), v.end()) 
#define err(x) cout << '#' << x << ':' << ' ' << x << endl 
typedef long long int ll; 
typedef map<int, int> mll; 
typedef set<int> si;  
typedef pair<int,int> pii; 
typedef vector<int> vci;
typedef vector<pii> vpii; 
typedef vector<string> vs; 
typedef vector<char> vcc; 

const int MaxN = 2e5 + 10; 
const int INF = 1e9 + 7; 

vector<int> adj[MaxN]; 
pair<int, int> val[MaxN];
ll maxSum[MaxN];
int ans;

void dfs(int v){
    for(int u: adj[v]){
        dfs(u);
        maxSum[v] += maxSum[u];
    }
    maxSum[v] = maxSum[v] < val[v].S ? maxSum[v] : val[v].S;

    if(maxSum[v] < val[v].F) {
        ans++, maxSum[v] = val[v].S;
    }
}

void clear_Arr(int n){
    forn(i,1,n + 1000) val[i].F = 0, val[i].S = 0;
    forn(i,1,2e5 + 10) maxSum[i] = 0;
    forn(i,1,2e5 + 10) adj[i].clear();
    ans = 0;
}

main()
{IOS;

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        clear_Arr(n);
        forn(i,2,n + 1){
            int x; cin >> x;
            adj[x].pb(i);
        }

        forn(i,1,n + 1){
            int x, y; cin >> x >> y;
            val[i] = {x, y};
        }


        dfs(1);

        cout << ans << endl;
        clear_Arr(n);
    }

}