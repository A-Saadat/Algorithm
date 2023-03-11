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

int a[MaxN];
vector<int> adj[MaxN]; 
int mid;

int dfs(int v){
    int sum = 0;

    for(int u: adj[v]){
        sum += dfs(u);
        cout << v << ' ' << sum << endl;
    }

    if(!adj[v].size()) return (mid - a[v]);

    if(a[v] > sum) return -0;
    else return (sum - a[v]);
}

main()
{IOS;

    int n; cin >> n;
    forn(i,2,n + 1){
        int x; cin >> x;
        adj[x].pb(i);
    }

    forn(i,1,n + 1) cin >> a[i];

    int L = -1, R = 10;
    while(R - L >= 1){
        mid = (L + R) / 2;
        cout << mid << ": ";

        if( !dfs(1) ) R = mid;
        else L = mid;

        cout << "\n--------\n";
    }

}