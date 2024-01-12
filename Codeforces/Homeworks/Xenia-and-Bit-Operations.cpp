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

const int MAX = 5e5 + 10; 
const int INF = 1e9 + 7; 

int a[MAX], res[4 * MAX]; 
int t, q, n; 

int _get(int id, int L, int R, int flag){ // ? flag == 0 ? xor || flag == 1 ? or
    if(L + 1 == R)
        return res[id] = a[L];
    
    int mid = (R + L) >> 1;
    int ret1 = _get(2 * id + 0, L, mid, 1 - flag);
    int ret2 = _get(2 * id + 1, mid, R, 1 - flag);

    if(flag == 0)
        return res[id] = (ret1 ^ ret2);
    else
        return res[id] = (ret1 | ret2);
}

void _set(int id, int L, int R, int idx, int val, int flag){
    if(L + 1 == R){
        a[idx] = val;
        res[id] = val;
        return;
    }

    int mid = (R + L) >> 1;
    if(idx < mid)
        _set(2 * id + 0, L, mid, idx, val, 1 - flag);
    else
        _set(2 * id + 1, mid, R, idx, val, 1 - flag);

    if(flag == 0)
        res[id] = res[2 * id + 0] ^ res[2 * id + 1];
    else
        res[id] = res[2 * id + 0] | res[2 * id + 1];
}

main()
{IOS;

    cin >> t >> q;
    n = (1 << t);
    for(int i = 1; i <= n; i++) cin >> a[i];
    _get(1, 1, n + 1, t % 2);

    while(q--){
        int idx, val; cin >> idx >> val;
        _set(1, 1, n + 1, idx, val, t % 2);
        cout << res[1] << endl;
    }

}