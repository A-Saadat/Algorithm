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
const int INF = 1e10 + 10; 

struct Segment{
    int res[4 * MAX], lazy[4 * MAX];
    inline void push(int id){
        lazy[2 * id + 0] |= lazy[id];
        res[2 * id + 0] |= lazy[id];
        lazy[2 * id + 1] |= lazy[id];
        res[2 * id + 1] |= lazy[id];
        lazy[id] = 0;
    }
    void set(int id, int L, int R, int l, int r, int val){
        if(L == l && R == r){
            lazy[id] |= val;
            res[id] |= val;
            return;
        }
        push(id);

        int mid = (L + R) >> 1;
        if(l < mid)
            set(2 * id + 0, L, mid, l, min(r, mid), val);
        if(r > mid) 
            set(2 * id + 1, mid, R, max(l, mid), r, val);

        res[id] = (res[2 * id + 0] & res[2 * id + 1]);
    }

    int get(int id, int L, int R, int l, int r){
        if(L == l && R == r)
            return res[id];

        push(id);
        int mid = (L + R) >> 1;
        int ret1 = INF, ret2 = INF;
        
        if(l < mid)
            ret1 = get(2 * id + 0, L, mid, l, min(r, mid));
        else
            ret2 = get(2 * id + 1, mid, R, max(l, mid), r);

        if(ret1 == INF)
            return ret2;
        elif(ret2 == INF)
            return ret1;
        else 
            return (ret1 & ret2);
    }
};

Segment seg;

main()
{IOS;

    int n, q; cin >> n >> q;
    while(q--){
        int t; cin >> t;
        int l, r; cin >> l >> r; ++l, ++r;
        if(t == 1){
            int val; cin >> val;
            seg.set(1, 1, n + 1, l, r, val);
        }
        else cout << seg.get(1, 1, n + 1, l, r) << endl;
    }
     
}