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

const int MAX = 1e6 + 50; 
const int M = 3e5 + 10;
const int INF = 1000 * 1000 + 5; 

int a[MAX], ans[M]; 
vector<int> s[MAX]; 
int sum[MAX];

struct Query{int r; int idx;};

vector<Query> que[MAX];
struct Fenwick{
    int get(int id){
        int ans = 0;
        while(id > 0){
            ans += sum[id];
            id ^= (id & -id);
        }
        return ans;
    }
    void set(int id, int delta){
        while(id <= INF){
            sum[id] += delta;
            id += (id & -id);
        }
    }
} fen;


main()
{IOS;

    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++){
        int l, r; cin >> l >> r;
        a[r] = 1;
        fen.set(r, a[r]);
        s[l].pb(r);
    }

    for(int i = 1; i <= q; i++){
        int cnt; cin >> cnt; vector<int> dot; ans[i] = n;
        for(int j = 1; j <= cnt; j++){
            int x; cin >> x;
            dot.pb(x);
        }

        que[0].pb( {dot[0], i} );
        for(int j = 1; j < cnt; j++){
            que[dot[j - 1] + 1].pb( {dot[j], i} );
        }

        que[dot[cnt - 1] + 1].pb({INF, i});
    }

    for(int i = 0; i <= INF + 10; i++){
        for(auto u: que[i]){
            int r = u.r, idx = u.idx;
            int res = fen.get(r - 1) - fen.get(i - 1);
            ans[idx] -= res;
        }
        for(int u: s[i]) fen.set(u, -1); 
        
    }

    for(int i = 1; i <= q; i++) cout << ans[i] << endl;

}