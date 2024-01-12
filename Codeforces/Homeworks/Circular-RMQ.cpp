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

const int MAX = 2e5 + 10; 
const int INF = 1e10 + 10; 

int a[MAX];

struct Segment{
    int mini[4 * MAX], lazy[4 * MAX];

    void build(int id, int l, int r){
        if(l + 1 == r){
            mini[id] = a[l];
            return;
        }

        int mid = (l + r) >> 1;
        build(2 * id + 0, l, mid);
        build(2 * id + 1, mid, r);

        mini[id] = min(mini[2 * id + 0], mini[2 * id + 1]);
    }

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
            set(2 * id + 0, L, mid, l, min(r, mid), val);
        if(r > mid)
            set(2 * id + 1, mid, R, max(l, mid), r, val);
        
        mini[id] = min(mini[2 * id + 0], mini[2 * id + 1]);
    }

    int get(int id, int L, int R, int l, int r){
        if(L == l && R == r)
            return mini[id];

        push(id);
        
        int mid = (L + R) >> 1;
        int ret1 = INF, ret2 = INF;
        if(l < mid)
            ret1 = get(2 * id + 0, L, mid, l, min(mid, r));
        if(r > mid)
            ret2 = get(2 * id + 1, mid, R, max(l, mid), r);

        return min(ret1, ret2);
    }
};

Segment seg;

main()
{IOS;

    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    seg.build(1, 1, n + 1);
    int q; cin >> q;
    while(q--){
        bool t = 0;
        int l, r, val = 0; cin >> l >> r; ++l, ++r;
        if(cin.peek() != '\n') cin >> val, t = 1;

        if(t == 1){
            if(l > r){
                seg.set(1, 1, n + 1, l, n + 1, val);
                seg.set(1, 1, n + 1, 1, r + 1, val);
            }
            else
                seg.set(1, 1, n + 1, l, r + 1, val);
        }
        else{
            int ans = INF;
            if(l > r){
                ans = min(ans, seg.get(1, 1, n + 1, l, n + 1));
                ans = min(ans, seg.get(1, 1, n + 1, 1, r + 1));
            }
            else
                ans = seg.get(1, 1, n + 1, l, r + 1);

            cout << ans << endl;
        }
    }

}