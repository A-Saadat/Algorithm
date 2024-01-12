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

const int MAX = 2e5 + 10; 
const int INF = 1e9 + 7; 

int a[MAX][10]; 
int sum[(1 << 6) + 10][MAX];

int n, k; 
struct Segment{
    vector<int> mini = vector<int>((MAX << 2), INF);
    vector<int> maxi = vector<int>((MAX << 2), -INF);
    void build(int id, int l, int r, int mask){
        if(l + 1 == r){
            mini[id] = maxi[id] = sum[mask][l];
            return;
        }
        int mid = (r + l) >> 1, lc = 2 * id, rc = 2 * id + 1;
        build(lc, l, mid, mask); build(rc, mid, r, mask);
        maxi[id] = max(maxi[lc], maxi[rc]);
        mini[id] = min(mini[lc], mini[rc]);
    }

    void set(int id, int l, int r, int idx, int val){
        if(l + 1 == r){
            mini[id] = val;
            maxi[id] = val;
            return;
        }
        int mid = (r + l) >> 1, lc = 2 * id, rc = 2 * id + 1;
        if(idx < mid)
            set(lc, l, mid, idx, val);
        else    
            set(rc, mid, r, idx, val);

        maxi[id] = max(maxi[lc], maxi[rc]);
        mini[id] = min(mini[lc], mini[rc]);
    }

    int get_max(int id, int L, int R, int l, int r){
        if(L == l && R == r) return maxi[id];

        int mid = (R + L) >> 1, lc = 2 * id, rc = 2 * id + 1;
        int ret1 = -INF, ret2 = -INF;
        if(l < mid)
            ret1 = get_max(lc, L, mid, l, min(r, mid));
        if(r > mid)
            ret2 = get_max(rc, mid, R, max(l, mid), r);

        return max(ret1, ret2);
    }

    int get_min(int id, int L, int R, int l, int r){
        if(L == l && R == r) return mini[id];

        int mid = (R + L) >> 1, lc = 2 * id, rc = 2 * id + 1;
        int ret1 = INF, ret2 = INF;
        if(l < mid)
            ret1 = get_min(lc, L, mid, l, min(r, mid));
        if(r > mid)
            ret2 = get_min(rc, mid, R, max(l, mid), r);

        return min(ret1, ret2);
    }

} seg[(1 << 6) + 1];

void fix_sum(int mask, int i){
    int res = 0;
    for(int j = 0; j < k; j++){
        if((mask >> j) & 1) res += a[i][j];
        else res -= a[i][j];
    }
    sum[mask][i] = res;
}

main()
{IOS;

    cin >> n >> k;
    for(int i = 1; i <= n; i++) for(int j = 0; j < k; j++) cin >> a[i][j];

    for(int mask = 0; mask < (1 << k); mask++){
        for(int i = 1; i <= n; i++) fix_sum(mask, i);
        seg[mask].build(1, 1, n + 1, mask);
    }

    int q; cin >> q;
    while(q--){
        int t; cin >> t;
        if(t == 1){ 
            int i; cin >> i;
            for(int j = 0; j < k; j++) cin >> a[i][j];
            for(int mask = 0; mask < (1 << k); mask++){
                fix_sum(mask, i);
                seg[mask].set(1, 1, n + 1, i, sum[mask][i]);
            } 
        }
        else{
            int l, r; cin >> l >> r; ++r;
            int mx, mn, ans = -INF;
            for(int mask = 0; mask < (1 << k); mask++){
                mx = seg[mask].get_max(1, 1, n + 1, l, r);
                mn = seg[mask].get_min(1, 1, n + 1, l, r);
                ans = max(ans, mx - mn);
            }

            cout << ans << endl;
        }
    }
}