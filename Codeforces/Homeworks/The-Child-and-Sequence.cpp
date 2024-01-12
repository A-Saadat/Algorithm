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

pair<int, int> maxi[(MAX << 2)];
int sum[(MAX << 2)];
int n, q; 
int a[MAX];

struct Segment{
    void build(int id = 1, int l = 1, int r = n + 1){
        if(l + 1 == r){
            maxi[id] = {a[l], l};
            sum[id] = a[l];
            return;
        }

        int mid = (r + l) >> 1, lc = (id << 1), rc = lc | 1;
        build(lc, l, mid);
        build(rc, mid, r);

        maxi[id] = max(maxi[lc], maxi[rc]);
        sum[id] = sum[lc] + sum[rc];
    }

    pair<int, int> get_max(int id, int L, int R, int l, int r){
        if(l == L && R == r)
            return maxi[id];

        int mid = (R + L) >> 1, lc = (id << 1), rc = lc | 1;
        pair<int, int> ret1 = {0, 0}, ret2 = {0, 0};
        if(l < mid)
            ret1 = get_max(lc, L, mid, l, min(r, mid));
        if(r > mid)
            ret2 = get_max(rc, mid, R, max(l, mid), r);

        return max(ret1, ret2);
    }

    int get_sum(int id, int L, int R, int l, int r){
        if(L == l && R == r)
            return sum[id];

        int mid = (R + L) >> 1, lc = (id << 1), rc = lc | 1, ret1 = 0, ret2 = 0;
        if(l < mid)
            ret1 = get_sum(lc, L, mid, l, min(r, mid));
        if(r > mid)
            ret2 = get_sum(rc, mid, R, max(l, mid), r);

        return ret1 + ret2;
    }

    void set(int id, int l, int r, int idx, int val){
        if(l + 1 == r){
            sum[id] = val;
            maxi[id] = {val, l};
            a[idx] = val;
            return;
        }

        int mid = (r + l) >> 1, lc = (id << 1), rc = lc | 1;
        if(idx < mid)
            set(lc, l, mid, idx, val);
        else
            set(rc, mid, r, idx, val);

        maxi[id] = max(maxi[lc], maxi[rc]);
        sum[id] = sum[lc] + sum[rc];
    }

} seg;

main()
{IOS;

    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];

    seg.build();

    while(q--){
        int type; cin >> type;
        if(type == 1) {
            int l, r; cin >> l >> r; ++r;
            cout <<  seg.get_sum(1, 1, n + 1, l, r) << endl;
        }
        elif(type == 2){
            int l, r, x; cin >> l >> r >> x; ++r;
            while(true){
                int idx = seg.get_max(1, 1, n + 1, l, r).S;
                if(a[idx] < x) break;
                seg.set(1, 1, n + 1, idx, a[idx] % x);
            }
        }
        else{
            int idx, val; cin >> idx >> val;
            seg.set(1, 1, n + 1, idx, val);
        }
    }

}