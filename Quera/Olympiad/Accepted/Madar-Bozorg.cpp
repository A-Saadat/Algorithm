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

vector<int> ps, a;
int n, q; 

struct Segment{
    int sum[(MAX << 2)];
    struct lz {int res; int cnt;} lazy[(MAX << 2)];
    void build(int id = 1, int l = 1, int r = n + 1){
        if(l + 1 == r){
            sum[id] = a[l];
            return;
        }
        int mid = (r + l) >> 1, lc = 2 * id + 0, rc = 2 * id + 1;
        build(lc, l, mid);
        build(rc, mid, r);

        sum[id] = sum[lc] + sum[rc];
        sum[id] = sum[id] % MOD;
    }

    void Mod_Gir(int id){
        while(sum[id] < 0) sum[id] += MOD;
        sum[id] = sum[id] % MOD;
    }

    void push(int id, int l, int r){
        int mid = (l + r) >> 1, lc = 2 * id + 0, rc = 2 * id + 1;
        lazy[lc].res += lazy[id].res;
        lazy[rc].res += lazy[id].res;
        lazy[lc].cnt += lazy[id].cnt;
        lazy[rc].cnt += lazy[id].cnt;
        
        sum[lc] = sum[lc] + ((1LL * (ps[mid - 1] - ps[l - 1]) * lazy[id].cnt)); Mod_Gir(lc);
        sum[lc] = sum[lc] - (1LL * lazy[id].res * (mid - l));
        Mod_Gir(lc);
        sum[rc] = sum[rc] + ((1LL * (ps[r - 1] - ps[mid - 1]) * lazy[id].cnt)); Mod_Gir(rc);
        sum[rc] = sum[rc] - (1LL * lazy[id].res * (r - mid));
        Mod_Gir(rc);

        lazy[id] = {0, 0};
    }

    void set(int id, int L, int R, int l, int r, int tl){
        if(l == L && R == r){
            sum[id] = sum[id] + ps[r - 1] - ps[l - 1] - ((tl - 1) * (r - l)); Mod_Gir(id);
            lazy[id].res = lazy[id].res + (tl - 1) % MOD;
            lazy[id].cnt += 1;
            return;
        }
        push(id, L, R);

        int mid = (R + L) >> 1, lc = 2 * id + 0, rc = 2 * id + 1;
        if(l < mid)
            set(lc, L, mid, l, min(r, mid), tl);
        if(r > mid)
            set(rc, mid, R, max(l, mid), r, tl);

        sum[id] = sum[lc] + sum[rc]; Mod_Gir(id);
    }

    int get(int id, int L, int R, int l, int r){
        if(L == l && R == r) return sum[id];
        push(id, L, R);
        int mid = (R + L) >> 1, lc = 2 * id + 0, rc = 2 * id + 1;   
        int res1 = 0, res2 = 0;
        if(l < mid)
            res1 = get(lc, L, mid, l, min(r, mid));
        if(r > mid)
            res2 = get(rc, mid, R, max(l, mid), r);

        int ans = res1 + res2; while(ans < 0) ans += MOD; ans = ans % MOD;
        return ans;
    }

} seg;

signed main()
{IOS;

    cin >> n >> q;
    ps.resize(n + 2); a.resize(n + 2);
    for(int i = 1; i <= n; i++) cin >> a[i], ps[i] = ps[i - 1] + i;
    seg.build();
    while(q--){
        string type; cin >> type;
        int l, r; cin >> l >> r; ++r;
        if(type == "add") seg.set(1, 1, n + 1, l, r, l);
        else cout << seg.get(1, 1, n + 1, l, r) << endl;
    }

}