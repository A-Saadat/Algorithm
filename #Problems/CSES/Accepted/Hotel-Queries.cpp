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
const int INF = 1e9 + 7; 

int maxi[(MAX << 2)]; 
int a[MAX];
int n, m;

struct Segment{
    void build(int id = 1, int L = 1, int R = n + 1){
        if(L + 1 == R){
            maxi[id] = a[L];
            return;
        }
        int mid = (R + L) >> 1;
        int lc = (id << 1), rc = lc | 1;
        build(lc, L, mid);
        build(rc, mid, R);

        maxi[id] = max(maxi[lc], maxi[rc]);
    }

    int get(int id, int l, int r, int val){
        if(l + 1 == r){
            if(a[l] >= val) return l;
            else return 0;
        }

        int mid = (l + r) >> 1, lc = (id << 1), rc = (lc | 1);
        if(maxi[lc] >= val) return get(lc, l, mid, val);
        elif(maxi[rc] >= val) return get(rc, mid, r, val);
        else return 0;
    }

    void set(int id, int l, int r, int idx, int val){
        if(l + 1 == r) {
            a[idx] = val;
            maxi[id] = val; 
            return;
        }

        int mid = (l + r) >> 1, lc = (id << 1), rc = (lc | 1);
        if(idx < mid)
            set(lc, l, mid, idx, val);
        else 
            set(rc, mid, r, idx, val);

        maxi[id] = max(maxi[lc], maxi[rc]);
    }

} seg;

main()
{IOS;

    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    seg.build();

    for(int i = 1; i <= m; i++){
        int x; cin >> x;
        int idx = seg.get(1, 1, n + 1, x);
        cout << idx << ' ';
        if(idx == 0) continue;
        seg.set(1, 1, n + 1, idx, max(1LL * 0, a[idx] - x));
    }


}