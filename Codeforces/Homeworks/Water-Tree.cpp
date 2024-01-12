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

const int MAX = 5e5 + 10; 
const int INF = 1e9 + 7; 

vector<int> adj[MAX];
int st[MAX], ft[MAX], a[MAX]; 

int t;
void dfs(int v, int p){
    st[v] = ++t;
    for(int u: adj[v]){
        if(u == p) continue;

        dfs(u, v);
    }

    ft[v] = t;
}

struct Segment_1{
    int num[4 * MAX];

    void set(int id, int L, int R, int l, int r, int val){
        if(L == l && R == r){
            num[id] = val;
            return;
        }

        int mid = (L + R) >> 1;
        if(l < mid)
            set(2 * id + 0, L, mid, l, min(r, mid), val);
        if(r > mid)
            set(2 * id + 1, mid, R, max(l, mid), r, val);
    }

    int get(int id, int l, int r, int idx){
        if(l + 1 == r)
            return num[id];

        int mid = (r + l) >> 1;
        int ret;
        if(idx < mid)
            ret = get(2 * id + 0, l, mid, idx);
        else    
            ret = get(2 * id + 1, mid, r, idx);

        return max(num[id], ret);
    }
};

struct Segment_2{
    int maxi[4 * MAX];

    void set(int id, int l, int r, int idx, int val){
        if(l + 1 == r){
            maxi[id] = val;
            return; 
        }   

        int mid = (l + r) >> 1;
        if(idx < mid)
            set(2 * id + 0, l, mid, idx, val);
        else 
            set(2 * id + 1, mid, r, idx, val);

        maxi[id] = max(maxi[2 * id + 0], maxi[2 * id + 1]);
    }

    int get(int id, int L, int R, int l, int r){
        if(L == l && R == r)
            return maxi[id];

        int ret1 = 0, ret2 = 0;
        int mid = (L + R) >> 1;
        if(l < mid)
            ret1 = get(2 * id + 0, L, mid, l, min(mid, r));
        if(r > mid)
            ret2 = get(2 * id + 1, mid, R, max(l, mid), r);
        
        return max(ret1, ret2);
    }
};

Segment_1 seg1;
Segment_2 seg2;

main()
{IOS;

    int n; cin >> n;
    for(int i = 1; i < n; i++){
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(1, 0);
    
    int q; cin >> q;
    for(int i = 1; i <= q; i++){
        int c, v; cin >> c >> v;
        if(c == 1)
            seg1.set(1, 1, n + 1, st[v], ft[v] + 1, i);
        elif(c == 2)
            seg2.set(1, 1, n + 1, st[v], i);
        else{
            int res1 = seg1.get(1, 1, n + 1, st[v]);
            int res2 = seg2.get(1, 1, n + 1, st[v], ft[v] + 1);

            cout << (res1 > res2 ? 1 : 0) << endl;
        }
    }

}