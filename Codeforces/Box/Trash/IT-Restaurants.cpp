#include <bits/stdc++.h> 
using namespace std; 

#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0) 
#define int long long int 
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
typedef vector<int> vi;

const int MaxN = 1e6; 
const int MOD = 1e9 + 7; 

vector<int> adj[MaxN]; 
int mark[MaxN], dsc[MaxN], beg[MaxN], endi[MaxN];
int ns[MaxN]; // ? Number of vertix in the Subtree of Vertix i
set<int> ans;

int t = 0;
void dfs(int v){
    ++t; mark[v] = 1; dsc[t] = v; beg[v] = t;

    for(int u: adj[v]){
        if(mark[u]) continue;
        
        dfs(u);
    }
    endi[v] = t;
}

main()
{IOS;

    int n; cin >> n;
    for(int i = 1; i < n; i++){
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    dfs(1);

    for(int i = 1; i <= n; i++)
        ns[i] = endi[i] - beg[i];

    for(int i = 1; i <= n - 2; i++){
        for(int j = 1; j <= n; j++)
            if(ns[j] == i) ans.insert(i), ans.insert(n - 1 - i);
    }

    cout << ans.size() << endl;
    fort(itr, ans) cout << *itr << " " << n - 1 - (*itr) << endl;

}




// cout << "\nDiscovery: \n";
// for(int i = 1; i <= n; i++) cout << "At Second " << i << " Vertix " << dsc[i] << " Was Seen. \n";
// cout << "\n--------------\nBegin: \n";
// for(int i = 1; i <= n; i++) cout << "the Vertix " << i << " Was seen At the Second " << beg[i] << " For the First Time. \n";
// cout << "\n--------------\nEnd: \n";
// for(int i = 1; i <= n; i++) cout << "the Vertix " << i << " Was seen At the Second " << endi[i] << " For the Last Time. \n";