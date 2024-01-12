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
typedef vector<int> vi;

const int MAX = 1e5 + 10; 
const int INF = 1e9 + 7; 
const int sq = 317;

struct Query{ int L; int R; int val; int idx; };

vector<int> adj[MAX]; 
vector<Query> v;
int col[MAX];
int cnt[MAX], cnt2[MAX];
int res[MAX];
int str[MAX], fin[MAX], dsc[MAX];


int t = 0;
inline void dfs(int v, int p){
    str[v] = ++t; dsc[t] = v;
    for(int u: adj[v]){
        if(u == p) continue;
        dfs(u, v);
    }
    fin[v] = t;
}

bool cmp(Query A, Query B){
    if(A.L / sq < B.L / sq) return 1;
    return ((A.L / sq == B.L / sq) && (A.R < B.L));
}

inline void add(int curr){
    cnt[dsc[curr]]++;
    cnt2[ cnt[dsc[curr]] ]++;
}

inline void remove(int curr){
    cnt2[ cnt[dsc[curr]] ]--;
    cnt[dsc[curr]]--;
}

main()
{IOS;

    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> col[i];
    for(int i = 1; i < n; i++){
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(1, 0);
    for(int i = 1; i <= n; i++)
        dsc[i] = col[dsc[i]];

    for(int i = 1; i <= q; i++){
        int vj, kj; cin >> vj >> kj;
        v.pb( {str[vj], fin[vj], kj, i} );
    }

    sort(all(v), cmp);

    int curr_L = 0, curr_R = 0; 
    for(auto u: v){
        int L = u.L, R = u.R, val = u.val, idx = u.idx;
        while(curr_L > L){
            curr_L--;
            add(curr_L);
        }
        while(curr_L < L){
            remove(curr_L);
            curr_L++;
        }
        while(curr_R > R){
            remove(curr_R);
            curr_R--;
        }
        while(curr_R < R){
            curr_R++;
            add(curr_R);
        }

        res[idx] = cnt2[val];
    }

    for(int i = 1; i <= q; i++){
        cout << res[i] << endl;
    }

}