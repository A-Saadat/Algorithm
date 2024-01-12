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
const int INF = 1e10; 

int lazy[4 * MAX], mini[4 * MAX]; 

struct Segment{
    inline void push(int id){
        lazy[2 * id + 0] += lazy[id];
        mini[2 * id + 0] += lazy[id];
        lazy[2 * id + 1] += lazy[id];
        mini[2 * id + 1] += lazy[id];
        lazy[id] = 0;
    }

    void set(int id, int L, int R, int l, int r, int val){
        if(L == l && R == r){
            lazy[id] += val;
            mini[id] += val;
            return;
        }
        push(id);
        
        int mid = (L + R) >> 1;
        if(l < mid)
            set(2 * id + 0, L, mid, l, min(mid, r), val);
        if(r > mid)
            set(2 * id + 1, mid, R, max(mid, l), r, val);

        mini[id] = min(mini[2 * id + 0], mini[2 * id + 1]);
    }

    int get(int id, int L, int R, int l, int r){
        if(L == l && R == r)
            return mini[id];

        push(id);
        
        int mid = (L + R) >> 1;
        int ret1 = INF, ret2 = INF;
        if(l < mid)
            ret1 = get(2 * id + 0, L, mid, l, min(r, mid));
        if(r > mid)
            ret2 = get(2 * id + 1, mid, R, max(l, mid), r);

        return min(ret1, ret2);
    }
};

Segment seg;

main()
{IOS;

    int n, q; cin >> n >> q;
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int l, r, v; cin >> l >> r >> v; ++l, ++r;
            seg.set(1, 1, n + 1, l, r, v);
        }
        else {
            int l, r; cin >> l >> r; ++l, ++r;
            cout << seg.get(1, 1, n + 1, l, r) << endl;
        }
    }

}