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
const int INF = 1e9 + 7; 

int que[MAX];
int a[MAX], who[4 * MAX]; 

struct Segment{
    void set(int id, int L, int R, int l, int r, int val){
        if(L == l && R == r){
            if(who[id] == INF) who[id] = val;
            return;
        }

        int mid = (L + R) >> 1;
        if(l < mid)
            set(2 * id + 0, L, mid, l, min(r, mid), val);
        if(r > mid)
            set(2 * id + 1, mid, R, max(l, mid), r, val);
    }

    int get(int id, int l, int r, int idx){
        if(l + 1 == r)
            return who[id];

        int mid = (r + l) >> 1;
        int res;
        if(idx < mid) 
            res = get(2 * id + 0, l, mid, idx);
        else
            res = get(2 * id + 1, mid, r, idx);

        return min(who[id], res);
    }
};

Segment seg;

main()
{IOS;

    int n, q; cin >> n >> q;
    for(int i = 0; i <= 4 * n; i++) who[i] = INF;
    for(int i = 1; i <= q; i++){
        int l, r, x; cin >> l >> r >> x;
        que[i] = x;
        seg.set(1, 1, n + 1, l, x, i);
        if(x == n) continue; 
        seg.set(1, 1, n + 1, x + 1, r + 1, i);
    }

    for(int i = 1; i <= n; i++){
        int res = seg.get(1, 1, n + 1, i);
        if(res == INF) cout << 0 << ' ';
        else cout << que[seg.get(1, 1, n + 1, i)] << ' ';
    } 
    
}