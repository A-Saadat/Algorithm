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
const int MOD = 1e9 + 9;
const int sq5 = 383008016;

int a[MAX], powA[MAX], powB[MAX]; 
int n, m; 

int cu_pow(int x, int y){
    int ans = 1;
    while(y > 0){
        if(y & 1) ans = 1LL * ans * x, ans = ans % MOD;
        x = 1LL * x * x; x = x % MOD;
        y >>= 1;
    }
    return ans % MOD;
}

struct Segment{
    int sum[(MAX << 2)];
    struct lz{int C; int D;} lazy[(MAX << 2)];

    int cal(int C, int D, int A, int B){
        int res1 = C * cu_pow(A - 1, MOD - 2); res1 = res1 % MOD;
        int res2 = D * cu_pow(B - 1, MOD - 2); res2 = res2 % MOD;
        int res3 = (res1 + res2) % MOD; res3 = 1LL * res * sq5 % MOD; res3 = 1LL * res3 * cu_pow(5, MOD - 2) % MOD; 
    }

    void build(int id = 1, int l = 1, int r = n + 1){
        if(l + 1 == r){
            sum[id] = a[l];
            return;
        }
        int mid = (r + l) >> 1, lc = 2 * id, rc = 2 * id + 1;
        build(lc, l, mid);
        build(rc, mid, r);

        sum[id] = sum[lc] + sum[rc];
    }

    void push(int id, int l, int r){
        int lc = 2 * id + 0, rc = 2 * id + 1;
        lazy[lc].C += lazy[id].C; lazy[lc].C = lazy[lc].C % MOD;
        lazy[lc].D += lazy[id].D; lazy[lc].D = lazy[lc].D % MOD;

        int res = cal(lazy[id].C * (powA[r - l] - 1) % MOD, lazy[id].D * (powB[r - l] - 1) % MOD, powA[1], powB[1]);
        
        sum[lc] = sum[lc] + res3;
        while(sum[lc] < 0) sum[lc] += MOD;
        sum[lc] = sum[lc] % MOD;


        lazy[rc].C += lazy[id].C * powA[(r - l) / 2]; lazy[rc].C = lazy[rc].C % MOD; 
        lazy[rc].D += lazy[id].D * powB[(r - l) / 2]; lazy[rc].D = lazy[rc].D % MOD;

        res1 = (1LL * ((lazy[id].C * powA[(r - l) / 2] % MOD) * (powA[r - l] - 1)) % MOD) * cu_pow(powA[1] - 1, MOD - 2); res1 = res1 % MOD;
        res2 = (1LL * ((lazy[id].D * powB[(r - l) / 2] % MOD) * (powB[r - l] - 1)) % MOD) * cu_pow(powB[1] - 1, MOD - 2); res2 = res2 % MOD;
        res3 = (res1 + res2) % MOD; res3 = 1LL * res * sq5 % MOD; res3 = 1LL * res3 * cu_pow(5, MOD - 2) % MOD; 
        sum[rc] = sum[rc] + res3;
        while(sum[rc] < 0) sum[rc] += MOD;
        sum[rc] = sum[rc] % MOD;

        lazy[id] = {0, 0};
    }

    void set(int id, int L, int R, int l, int r, int tl){
        if(L == l && R == r){
            int idx = l - tl + 1;
            lazy[id].C += powA[idx];
            lazy[id].D += powB[idx];
            int res = powA[idx] * pow
        }
    }
    int get(int id, int L, int R, int l, int r){

    }

} seg;

main()
{IOS;


    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];

    powA[1] = 1LL * (1 + sq5 + MOD) * cu_pow(2, MOD - 2); powA[1] = powA[1] % MOD;
    powB[1] = 1LL * (1 - sq5 + MOD) * cu_pow(2, MOD - 2); powB[1] = powB[1] % MOD;
    for(int i = 2; i <= n + 10; i++){
        powA[i] = 1LL * powA[i - 1] * powA[1]; powA[i] = powA[i] % MOD;
        powB[i] = 1LL * powB[i - 1] * powB[1]; powB[i] = powB[i] % MOD;
    }

    seg.build();
    while(m--){
        int t, l, r; cin >> t >> l >> r; ++r;
        if(t == 1) seg.set(1, 1, n + 1, l, r, l);
        else seg.get(1, 1, n + 1, l, r);
    }

}