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

int a[MAX], b[MAX], c[MAX], suf[MAX]; 
int n, q; 
int maxi[(MAX << 2)], lz[(MAX << 2)];

struct Segment{
    void build(int id = 1, int l = 1, int r = n + 1){
        if(l + 1 == r){
            maxi[id] = suf[l];
            return;
        }
        int mid = (r + l) >> 1, lc = id * 2, rc = lc + 1;
        build(lc, l, mid);
        build(rc, mid, r);

        maxi[id] = max(maxi[lc], maxi[rc]);
    }

    void push(int id){
        int lc = 2 * id, rc = lc + 1;

        lz[lc] += lz[id];
        lz[rc] += lz[id];
        maxi[lc] += lz[id];
        maxi[rc] += lz[id];

        lz[id] = 0;
    }

    void set(int id, int L, int R, int l, int r, int val){
        if(L == l && R == r){
            lz[id] += val;
            maxi[id] += val;
            return;
        }

        push(id);
        int mid = (L + R) >> 1, lc = 2 * id, rc = lc + 1;
        if(l < mid)
            set(lc, L, mid, l, min(mid, r), val);
        if(r > mid)
            set(rc, mid, R, max(l, mid), r, val);

        maxi[id] = max(maxi[lc], maxi[rc]);
    }

} seg;

main()
{IOS;

    cin >> n >> q;
    int sum = 0;
    for(int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];    
    for(int i = 1; i < n; i++) cin >> c[i];    
    for(int i = n; i >= 1; i--) suf[i] = suf[i + 1] + (a[i] - b[i]);

    seg.build();

    while(q--){
        int p, x, y, z; cin >> p >> x >> y >> z;
        seg.set(1, 1, n + 1, 1, p + 1, -(a[p] - b[p]));
        sum -= a[p]; 
        a[p] = x, b[p] = y; 
        sum += a[p];
        seg.set(1, 1, n + 1, 1, p + 1, (a[p] - b[p]));
        cout << sum - max(maxi[1], 1LL * 0) << endl;
    }

}