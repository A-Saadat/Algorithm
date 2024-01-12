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
    int mid = (l + r) >> 1;
    _build(2 * id + 0, l, mid);
    _build(2 * id + 1, mid, r);

    sum[id] = sum[2 * id + 0] + sum[2 * id + 1];
}

void _set(int id, int l, int r, int idx){
    if(l + 1 == r){
        a[idx] = 1 - a[idx];
        sum[id] = a[idx];
        return;
    }
    
    int mid = (l + r) >> 1;
    if(idx < mid)
        _set(2 * id + 0, l, mid, idx);
    else
        _set(2 * id + 1, mid, r, idx);

    sum[id] = sum[2 * id + 0] + sum[2 * id + 1];
}

int _get(int id, int l, int r, int k){
    if(l + 1 == r)
        return l;

    int mid = (l + r) >> 1;
    if(sum[2 * id + 0] >= k)
        return _get(2 * id + 0, l, mid, k);
    else
        return _get(2 * id + 1, mid, r, k - sum[2 * id + 0]);
}

main()
{IOS;

    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    _build(1, 1, n + 1);
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int idx; cin >> idx; ++idx;
            _set(1, 1, n + 1, idx);
        } 
        else{
            int k; cin >> k; ++k;
            cout << _get(1, 1, n + 1, k) - 1 << endl;
        }
    }

}