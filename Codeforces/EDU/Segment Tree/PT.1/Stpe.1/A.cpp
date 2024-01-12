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
const int INF = 1e9 + 7; 

int a[MAX], sum[4 * MAX]; 

void _build(int id, int l, int r){
    if(l + 1 == r){
        sum[id] = a[l];
        return;
    }

    int mid = (r + l) >> 1;
    _build(2 * id + 0, l, mid);
    _build(2 * id + 1, mid, r);

    sum[id] = sum[2 * id + 0] + sum[2 * id + 1];
}

void _set(int id, int l, int r, int idx, int val){
    if(l + 1 == r){
        sum[id] = val;
        a[idx] = val;
        return;
    }

    int mid = (r + l) >> 1;
    if(idx < mid)
        _set(2 * id + 0, l, mid, idx, val);
    else
        _set(2 * id + 1, mid, r, idx, val);

    sum[id] = sum[2 * id + 0] + sum[2 * id + 1];
}

int _get(int id, int L, int R, int l, int r){
    if(L == l && R == r)
        return sum[id];

    int mid = (L + R) >> 1;
    int ret1 = 0, ret2 = 0;
    if(l < mid)
        ret1 = _get(2 * id + 0, L, mid, l, min(r, mid));
    if(r > mid)
        ret2 = _get(2 * id + 1, mid, R, max(mid, l), r);

    return ret1 + ret2;
}

main()
{IOS;

    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    _build(1, 1, n + 1);
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int idx, val; cin >> idx >> val; ++idx;
            _set(1, 1, n + 1, idx, val);
        }
        else{
            int l, r; cin >> l >> r; ++l; ++r;
            cout << _get(1, 1, n + 1, l, r) << endl;
        }
    }

}