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

int sum[MAX], a[MAX]; 

void init(int id, int L, int R){
    if(L + 1 == R){
        sum[id] = a[L];
        return;
    }

    int mid = (R + L) >> 1;
    init(2 * id + 0, L, mid);
    init(2 * id + 1, mid, R);

    sum[id] = sum[2 * id + 0] + sum[2 * id + 1];
}

void _set(int id, int L, int R, int idx, int val){
    if(L + 1 == R){
        sum[id] = val;
        a[idx] = val;
        return;
    }

    int mid = (R + L) >> 1;
    if(idx < mid)
        _set(2 * id + 0, L, mid, idx, val);
    else 
        _set(2 * id + 1, mid, R, idx, val);

    sum[id] = sum[2 * id + 0] + sum[2 * id + 1];
}

int _get(int id, int L, int R, int l, int r){
    int ret1 = 0, ret2 = 0;
    if(L == l && R == r)
        return sum[id];

    int mid = (R + L) >> 1;
    if(l < mid)
        ret1 = _get(2 * id + 0, L, mid, l, min(mid, r));
    if(r > mid)
        ret2 = _get(2 * id + 1, mid, R, max(mid, l), r);

    return ret1 + ret2;
}

main()
{IOS;

    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    init(1, 1, n + 1);
    int q; cin >> q;
    while(q--){
        int type; cin >> type;
        if(type == 1){
            int idx, x; cin >> idx >> x;
            _set(1, 1, n + 1, idx, x);
        }
        elif(type == 2){
            int l, r; cin >> l >> r;
            cout << "-> " << _get(1, 1, n + 1, l, r + 1) << endl;
        }
    }

}