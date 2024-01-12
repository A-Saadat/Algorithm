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
const int MOD = 1e9 + 9; 

int par[MAX];
int n, m, ans = 1;

int Find_par(int x){
    if(x == par[x]) return x;
    return par[x] = Find_par(par[x]);
}

void DSU(int x, int y){
    x = Find_par(x), y = Find_par(y);
    if(x == y) ans = 1LL * ans * 2, ans = ans % MOD;
    else par[x] = y;
}

main()
{IOS;

    cin >> n >> m;
    for(int i = 1; i <= n; i++) par[i] = i;
    for(int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        DSU(x, y);
        cout << ans - 1 << endl;
    }
}