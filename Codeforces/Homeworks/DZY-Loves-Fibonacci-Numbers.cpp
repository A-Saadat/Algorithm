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

const int MAX = 3e5 + 10; 
const int MOD = 1e9 + 9;
const int sq5 = 383008016;
const int div5 = 200000002;
const int divA = 691504013;
const int divB = 308495997;
const int div2 = 500000005;

int all[MAX]; 
int n, q, A, B; // ? (1 + sq5) / 2, (1 - sq5) / 2 

int powA[MAX], powB[MAX];

struct Segment{
    int sum[(MAX << 2)];
    struct lzy{int a; int b;} lazy[(MAX << 2)];

    void build(int id = 1, int l = 1, int r = n + 1){
        if(l + 1 == r){
            sum[id] = all[l];
            return;
        }
        int mid = (r + l) >> 1, lc = 2 * id, rc = lc + 1;
        build(lc, l, mid);
        build(rc, mid, r);
        sum[id] = sum[lc] + sum[rc]; 
    }

    int cal(int x, int y, int sz){
        int res = 1LL * x * ((y == A ? powA[sz] : powB[sz]) - 1); res = res % MOD;
        res = res * (y == A ? divA : divB); res = res % MOD;
        return res % MOD;
    }

    void push(int id, int l, int r){
        int mid = (r + l) / 2, lc = 2 * id, rc = lc + 1;

        int t1 = 1LL * lazy[id].a * powA[(r - l) / 2]; t1 = t1 % MOD;
        int t2 = 1LL * lazy[id].b * powB[(r - l) / 2]; t2 = t2 % MOD;

        lazy[lc].a += lazy[id].a; lazy[lc].a = lazy[lc].a % MOD;
        lazy[lc].b += lazy[id].b; lazy[lc].b = lazy[lc].b % MOD;

        lazy[rc].a += t1; lazy[rc].a = lazy[rc].a % MOD;
        lazy[rc].b += t2; lazy[rc].b = lazy[rc].b % MOD;

        int res = cal(lazy[id].a, A, mid - l);
        res = res - cal(lazy[id].b, B, mid - l);
        while(res < 0) res += MOD; res = res % MOD;

        res = 1LL * res * sq5; res = res % MOD;
        res = 1LL * res * div5; res = res % MOD;
        sum[lc] = sum[lc] + res; sum[lc] = sum[lc] % MOD;

        // ? ------------------------------- ? \\

        res = cal(t1, A, r - mid);
        res -= cal(t2, B, r - mid);
        while(res < 0) res += MOD; res = res % MOD;

        res = 1LL * res * sq5; res = res % MOD;
        res = 1LL * res * div5; res = res % MOD;
        sum[rc] = sum[rc] + res; sum[rc] = sum[rc] % MOD;

        lazy[id] = {0, 0};
    }

    void set(int id, int L, int R, int l, int r, int tl){
        if(L == l && R == r){
            int fr = l - tl + 1;

            int aa = powA[fr];
            int bb = powB[fr];
            
            lazy[id].a += aa; lazy[id].b += bb; 
            lazy[id].a = lazy[id].a % MOD; lazy[id].b = lazy[id].b % MOD;

            int S1 = cal(aa, A, r - l);
            int S2 = cal(bb, B, r - l);

            int res = S1 - S2;
            while(res < 0) res += MOD; res = res % MOD;

            res = 1LL * res * sq5; res = res % MOD;
            res = 1LL * res * div5; res = res % MOD;
            sum[id] = sum[id] + res; sum[id] = sum[id] % MOD;
            return;
        }

        push(id, L, R);
        int mid = (R + L) >> 1, lc = 2 * id, rc = lc + 1;
        
        if(l < mid) 
            set(lc, L, mid, l, min(mid, r), tl);
        if(r > mid)
            set(rc, mid, R, max(mid, l), r, tl);

        sum[id] = sum[lc] + sum[rc]; sum[id] = sum[id] % MOD;
    }

    int get(int id, int L, int R, int l, int r){
        if(L == l && R == r)
            return sum[id];

        push(id, L, R);
        int mid = (L + R) >> 1, lc = 2 * id, rc = lc + 1;
        int res1 = 0, res2 = 0;
        
        if(l < mid) 
            res1 = get(lc, L, mid, l, min(mid, r));
        if(r > mid)
            res2 = get(rc, mid, R, max(mid, l), r);

        int ans = res1 + res2; ans = ans % MOD;
        return ans;
    }

} seg;

main()
{IOS;

    A = 1LL * (1 + sq5) * div2 % MOD;
    B = 1LL * (1 - sq5) * div2;
    while(B < 0) B += MOD;
    B = B % MOD; 


    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> all[i];
    
    powA[1] = A, powB[1] = B; 
    for(int i = 2; i <= n + 2; i++){
        powA[i] = 1LL * powA[i - 1] * A; powA[i] = powA[i] % MOD;
        powB[i] = 1LL * powB[i - 1] * B; powB[i] = powB[i] % MOD;
    }

    seg.build();

    while(q--){
        int t, l, r; cin >> t >> l >> r; ++r;
        if(t == 1) seg.set(1, 1, n + 1, l, r, l);
        else cout << seg.get(1, 1, n + 1, l, r) << endl;
    }
}