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

const int MAX = 1e6 + 10; 
const int INF = 1e9; 

int a[MAX], sum[4 * MAX + 1][3]; 
int b[MAX][3];
int n; 

inline void Compress(){
    vector<int> v;
    for(int i = 1; i <= n; i++) v.pb(a[i]);

    sort(all(v));
    for(int i = 1; i <= n; i++)
        a[i] = lower_bound(all(v), a[i]) - v.begin() + 1;
}

void init(int id, int L, int R){
    if(L + 1 == R){
        sum[id][1] = b[L][1];
        return;
    }
    int mid = (R + L) >> 1;
    init(2 * id + 0, L, mid);
    init(2 * id + 1, mid, R);

    sum[id][1] = sum[2 * id + 0][1] + sum[2 * id + 1][1];
}

void _set(int id, int L, int R, int idx, int val, int flag){
    if(L + 1 == R){
        b[idx][flag] = val;
        sum[id][flag] = val;
        return;
    }

    int mid = (R + L) >> 1;
    if(idx < mid)
        _set(2 * id + 0, L, mid, idx, val, flag);
    else
        _set(2 * id + 1, mid, R, idx, val, flag);
    
    sum[id][flag] = sum[2 * id + 0][flag] + sum[2 * id + 1][flag];
}

int _get(int id, int L, int R, int l, int r, int flag){
    if(L == l && R == r)
        return sum[id][flag];

    int ret1 = 0, ret2 = 0;
    int mid = (R + L) >> 1;
    if(l < mid)
        ret1 = _get(2 * id + 0, L, mid, l, min(mid, r), flag);
    if(r > mid)
        ret2 = _get(2 * id + 1, mid, R, max(mid, l), r, flag);

    return ret1 + ret2;
}


main()
{IOS;

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i], a[i] = a[i] * -1;
    Compress();
    
    for(int i = 1; i <= n; i++) b[i][0] = 0, b[i][1] = 1;
    init(1, 1, n + 1);

    int ans = 0;
    for(int i = 1; i <= n; i++){
        
        _set(1, 1, n + 1, a[i], 1, 0);
        _set(1, 1, n + 1, a[i], 0, 1);

        int r1 = _get(1, 1, n + 1, 1, a[i], 0);
        int r2 = _get(1, 1, n + 1, a[i], n + 1, 1); // ? [,)
        ans += r1 * r2;
    }

    cout << ans << endl;

}