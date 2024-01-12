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
const int MOD = 1e9 + 7; 

int a[MAX]; 
int n, q; 
bool isOk =0;

struct Segment{
    int C(int x){
        return (x * (x - 1)) / 2;
    }

    struct lz{int x; int cnt;} lazy[(MAX << 2)];
    int sum[(MAX << 2)];

    void build(int id = 1, int l = 1, int r = n + 1){
        if(l + 1 == r){
            sum[id] = a[l];
            return;
        }
        int mid = (r + l) >> 1, lc = 2 * id + 0, rc = 2 * id + 1;
        build(lc, l, mid);
        build(rc, mid, r);

        sum[id] = sum[lc] + sum[rc] % MOD;
    }

    void push(int id, int l, int r){
        int lc = 2 * id + 0, rc = 2 * id + 1;   
        lazy[lc].x += lazy[id].x;
        lazy[rc].x += lazy[id].x + (((r - l) / 2) * lazy[id].cnt);
        lazy[lc].cnt += lazy[id].cnt;
        lazy[rc].cnt += lazy[id].cnt;
        lazy[id] = {0, 0};
    }

    int get(int id, int L, int R, int l, int r){
        if(L == l && R == r){
            int resX = 1LL * (lazy[id].x * (R - L)); resX = resX % MOD;
            int resC = 1LL * (C(R - L) * lazy[id].cnt); resC = resC % MOD;
            sum[id] = sum[id] + resX + resC; sum[id] = sum[id] % MOD;
            // if(isOk)
            //     cout << "id = " << id << " / [" << l << ", " << r - 1 << "] || {" << lazy[id].x << ", " << lazy[id].cnt << "} / sum = " << sum[id] << endl;
            return sum[id];
        }
        push(id, L, R);

        int mid = (R + L) >> 1, lc = 2 * id + 0, rc = 2 * id + 1;
        int res1 = 0, res2 = 0;
        if(l < mid)
            res1 = get(lc, L, mid, l, min(r, mid));
        if(r > mid)
            res2 = get(rc, mid, R, max(l, mid), r);

        int ans = res1 + res2 % MOD;
        return ans;
    }

    void set(int id, int L, int R, int l, int r, int tl){
        if(L == l && R == r){
            lazy[id].x += tl - l + 1;
            lazy[id].cnt += 1;
            int resX = 1LL * (lazy[id].x * (R - L)); resX = resX % MOD;
            int resC = 1LL * (C(R - L) * lazy[id].cnt); resC = resC % MOD;
            sum[id] = sum[id] + resX + resC; sum[id] = sum[id] % MOD;
            if(R - L > 1) push(id, L, R);
            return;
        }
        push(id, L, R);

        int mid = (R + L) >> 1, lc = 2 * id + 0, rc = 2 * id + 1;
        if(l < mid)
            set(lc, L, mid, l, min(r, mid), tl);
        if(r > mid)
            set(rc, mid, R, max(l, mid), r, tl);

        sum[id] = sum[lc] + sum[rc]; sum[id] = sum[id] % MOD;
    }

} seg;

main()
{IOS;

    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    seg.build();
    while(q--){
        string type; cin >> type;
        int l, r; cin >> l >> r; ++r;

        if(type == "ask"){
            // if(l == 2 && r == 6) isOk = 1;
            cout << "-> Ans:\n" << seg.get(1, 1, n + 1, l, r) << endl;
            // cout << "\n-------------\n";
        } 
        else{
            
            seg.set(1, 1, n + 1, l, r, l);
        } 
    }

}