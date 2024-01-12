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
const int MOD = 1e9 + 7; 

int a[MAX];
int sum[4 * MAX], lazy[4 * MAX];

struct Segment{
    vector<int> aa, bb[MAX];
    void build(int id, int l, int r, int val){
        if(l + 1 == r){
            sum[id] = 1;
            return;
        }

        int mid = (l + r) >> 1;
        build(2 * id + 0, l, mid, val);
        build(2 * id + 1, mid, r, val);

        sum[id] = sum[2 * id + 0] + sum[2 * id + 1];
    }

    inline void push(int id){
        lazy[2 * id + 0] = (lazy[2 * id + 0] * lazy[id]) % MOD;
        sum[2 * id + 0] = (sum[2 * id + 0] * lazy[id]) % MOD;
        lazy[2 * id + 1] = (lazy[2 * id + 1] * lazy[id]) % MOD;
        sum[2 * id + 1] = (sum[2 * id + 1] * lazy[id]) % MOD;
        lazy[id] = 1;
    }

    void set(int id, int L, int R, int l, int r, int val){
        if(L == l && R == r){
            lazy[id] = (lazy[id] * val) % MOD;
            sum[id] = (sum[id] * val) % MOD;
            return;
        }
        push(id);
        
        int mid = (L + R) >> 1;
        if(l < mid)
            set(2 * id + 0, L, mid, l, min(mid, r), val);
        if(r > mid)
            set(2 * id + 1, mid, R, max(l, mid), r, val); 

        sum[id] = (sum[2 * id + 0] + sum[2 * id + 1]) % MOD;
    }

    int get(int id, int L, int R, int l, int r){
        if(L == l && R == r)
            return sum[id];
        
        push(id);
        int mid = (L + R) >> 1;

        int ret1 = 0, ret2 = 0;
        if(l < mid)
            ret1 = get(2 * id + 0, L, mid, l, min(r, mid));
        if(r > mid)
            ret2 = get(2 * id + 1, mid, R, max(l, mid), r);

        return (ret1 + ret2) % MOD;
    }

};

Segment seg;

main()
{IOS;

    int n; cin >> n;
    for(int i = 1; i <= n; i++) a[i] = 1;
    for(int i = 1; i <= 4 * n; i++) lazy[i] = 1;

    seg.build(1, 1, n + 1, 1);
    int q; cin >> q;
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int l, r, val; cin >> l >> r >> val; ++l, ++r;
            seg.set(1, 1, n + 1, l, r, val);
        }
        else{
            int l, r; cin >> l >> r; ++l, ++r;
            cout << seg.get(1, 1, n + 1, l, r) << endl;
        }
    }

}