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

const int MAX = 1e5 + 10; 
const int foo = (1 << 30) - 1;
const int INF = 1e9 + 7; 

int num[4 * MAX], lazy[4 * MAX];

struct Segment{
    inline void push(int id){
        lazy[2 * id + 0] |= lazy[id];
        num[2 * id + 0] |= lazy[id];
        lazy[2 * id + 1] |= lazy[id];
        num[2 * id + 1] |= lazy[id];
        lazy[id] = 0;
    }

    int set(int id, int L, int R, int l, int r, int val){
        if(L == l && R == r){
            num[id] |= val;
            lazy[id] |= val;
            return num[id];
        }
        push(id);
        
        int mid = (R + L) >> 1;
        int ret1 = foo, ret2 = foo;
        if(l < mid)
            ret1 = set(2 * id + 0, L, mid, l, min(r, mid), val);
        if(r > mid)
            ret2 = set(2 * id + 1, mid, R, max(l, mid), r, val);

        return (ret1 & ret2);
    }

    int get(int id, int l, int r, int idx){
        if(l + 1 == r)
            return num[id];

        push(id);
        int mid = (r + l) >> 1;
        if(idx < mid)
            return get(2 * id + 0, l, mid, idx);
        else
            return get(2 * id + 1, mid, r, idx);
    }

    int check(int id, int L, int R, int l, int r){
        if(L == l && R == r)
            return num[id];

        push(id);
        int mid = (R + L) >> 1;
        int ret1 = foo, ret2 = foo;
        if(l < mid)
            ret1 = check(2 * id + 0, L, mid, l, min(r, mid));
        if(r > mid)
            ret2 = check(2 * id + 1, mid, R, max(l, mid), r);

        return (ret1 & ret2);
    }
};

Segment seg;
vector<pair<pair<int, int>, int>> que;

main()
{IOS;

    bool isOk = 1;
    int n, m; cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int l, r, val; cin >> l >> r >> val;
        que.pb({{l, r}, val});
        int res = seg.set(1, 1, n + 1, l, r + 1, val);
        if(res != val) isOk = 0;
    }

    for(auto u: que){
        int l = u.F.F, r = u.F.S, val = u.S;
        int res = seg.check(1, 1, n + 1, l, r + 1);
        if(res != val) isOk = 0;
    }

    if(isOk){
        cout << "YES\n";
        for(int i = 1; i <= n; i++) cout << seg.get(1, 1, n + 1, i) << ' ';
    } 
    else cout << "NO\n";

}