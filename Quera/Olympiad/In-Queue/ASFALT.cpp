///** آسفالت
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

const int MAX = 1e6; 
const int INF = 1e9 + 7; 

vector< pair<int, pair<int, int>> > edg;
int n, m; 

int par[MAX], sz[MAX];
int Find_par(int v){
    if(par[v] == v) return v;
    return par[v] = Find_par(par[v]);
}

void merge(int A, int B){
    A = Find_par(A); B = Find_par(B);
    if(A == B) return;

    if(sz[A] > sz[B]) swap(A, B);
    par[A] = B;
    sz[B] += sz[A];
}

bool DSU(int v, int k, int mid){
    for(int i = 1; i <= n; i++) par[i] = i, sz[i] = 1;

    for(auto u: edg){
        auto [x, y] = u.S;
        int w = u.F;
        if(w > mid) break;
        merge(x, y);
    }

    return (sz[Find_par(v)] >= k); 
}

signed main()
{IOS;

    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x, y, w; cin >> x >> y >> w;
        edg.pb({w, {x, y} });
    }

    sort(all(edg));

    int q; cin >> q;
    while(q--){
        int v, k; cin >> v >> k;

        int L = 0, R = INF;
        while(R - L > 1){
            int mid = (R + L) / 2;
            if(!DSU(v, k, mid)) L = mid;
            else R = mid;
        }
        cout << (R == INF ? -1 : R) << endl;
    }

}