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
#define err_dp(i, j) cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
#define int long long 

const int MAX = 35000 + 10; 
const int M = 50 + 10;
const int INF = 1e9 + 7; 

int dp[MAX][M], a[MAX];
int n, k;
int maxi[(MAX << 2)][M];
int lazy[(MAX << 2)][M];

struct Segment{

    void build(int id = 1, int l = 1, int r = n + 1){
        if(l + 1 == r){
            maxi[id][1] = dp[l][1];
            return;
        }

        int mid = (r + l) >> 1;
        build(2 * id + 0, l, mid);
        build(2 * id + 1, mid, r);

        maxi[id][1] = max(maxi[2 * id + 0][1], maxi[2 * id + 1][1]);
    }

    void push(int id, int row){
        int lc = (id << 1), rc = id | 1;
        lazy[lc][row] += lazy[id][row];
        maxi[lc][row] += lazy[id][row];
        lazy[rc][row] += lazy[id][row];
        maxi[rc][row] += lazy[id][row];
        lazy[id][row] = 0;
    }

    void set(int id, int L, int R, int l, int r, int row){
        if(L == l && R == r){
            maxi[id][row] += 1;
            lazy[id][row] += 1;
            return;
        }

        push(id, row);

        int mid = (R + L) >> 1;
        if(l < mid)
            set(2 * id + 0, L, mid, l, min(mid, r), row);
        if(r > mid)
            set(2 * id + 1, mid, R, max(l, mid), r, row);

        maxi[id][row] = max(maxi[2 * id + 0][row], maxi[2 * id + 1][row]);
    }

    int get(int id, int L, int R, int l, int r, int row){
        if(L == l && R == r)
            return maxi[id][row];

        push(id, row);

        int mid = (R + L) >> 1, ret1 = 0, ret2 = 0;
        if(l < mid)
            ret1 = get(2 * id + 0, L, mid, l, min(r, mid), row);
        if(r > mid)
            ret2 = get(2 * id + 1, mid, R, max(l, mid), r, row);

        return max(ret1, ret2);
    }

} seg;

int ef[MAX], last[MAX];

main()
{IOS;

    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i], ef[i] = last[a[i]] + 1, last[a[i]] = i; //, cout << i << ": [" << ef[i] << ", " << i << "]\n";

    vector<bool> mark(MAX + 1); int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(!mark[a[i]]) cnt++, mark[a[i]] = 1;
        dp[1][i] = cnt;
        // err_dp(1, i);
    }

    seg.build();

    for(int i = 2; i <= k; i++){
        for(int j = 1; j <= n; j++){
            seg.set(1, 1, n + 1, ef[j], j + 1, i - 1);
            dp[i][j] = seg.get(1, 1, n + 1, 1, j, i - 1);
        }
    }

    for(int i = 1; i <= k; i++){
        for(int j = 1; j <= n; j++){
            err_dp(i, j);
        }
        cout << "\n----------------------\n";
    }
}