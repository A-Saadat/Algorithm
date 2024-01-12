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

const int MAX = 1e6; 
const int INF = 1e9 + 7; 

vector<int> a, c;
int par[MAX][30];

int bl(int v){
    for(int i = 22; i >= 0; i--){
        if(!a[par[v][i]]) continue;
        v = par[v][i];
    }
    return v;
}

pair<int, int> Solve(int v, int w){
    pair<int, int> ans; // ? ans.First == cnt, ans.Second == cost
    while(w > 0){
        int t = bl(v);
        if(!a[t]) break;

        ans.F += min(w, a[t]);
        ans.S += min(w, a[t]) * c[t];
        int at = max(1LL * 0, a[t] - w), fk = max(1LL * 0, w - a[t]);
        a[t] = at;
        w = fk;
    }
    return ans;
}

main()
{IOS;

    int q; cin >> q;
    a.resize(q + 3); c.resize(q + 3);
    cin >> a[1] >> c[1];

    for(int i = 2; i <= q + 1; i++){
        int t; cin >> t;
        if(t == 1){
            cin >> par[i][0] >> a[i] >> c[i]; par[i][0]++;
            for(int k = 1; k <= 22; k++) par[i][k] = par[par[i][k - 1]][k - 1];
        }
        else{
            int v, w; cin >> v >> w; v++;
            pair<int, int> ans = Solve(v, w);
            cout << ans.F << " " << ans.S << endl;
        }
    }
}