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
const int N = 1e5 + 10;
const int INF = 1e9 + 7; 

vector< pair<int, int> > str[MAX], fin[MAX];

pair<int, int> mini[(MAX << 2)];
int lazy[(MAX << 2)];

struct Segment{
    void build(int id = 1, int L = 1, int R = N + 1){
        if(L + 1 == R){
            mini[id] = {0, 1};
            return;
        }

        int mid = (R + L) >> 1;
        build(2 * id + 0, L, mid);
        build(2 * id + 1, mid, R);

        mini[id] = {0, mini[2 * id + 0].S + mini[2 * id + 1].S};
    }

    void push(int id){
        int lc = (id << 1), rc = lc | 1;
        lazy[lc] += lazy[id];
        lazy[rc] += lazy[id];
        mini[lc].F += lazy[id];
        mini[rc].F += lazy[id];
        lazy[id] = 0;
    }

    void set(int id, int L, int R, int l, int r, int val){
        if(L == l && R == r){
            mini[id].F += val;
            lazy[id] += val;
            return;
        }
        push(id);

        int mid = (R + L) >> 1, lc = (id << 1), rc = lc | 1;
        if(l < mid)
            set(lc, L, mid, l, min(r, mid), val);
        if(r > mid)
            set(rc, mid, R, max(l, mid), r, val);

        if(mini[lc].F < mini[rc].F) mini[id] = mini[lc];
        elif(mini[rc].F < mini[lc].F) mini[id] = mini[rc];
        else mini[id] = {mini[lc].F, mini[lc].S + mini[rc].S};
    }

} seg;

main()
{IOS;

    seg.build();

    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        int x1, y1; cin >> x1 >> y1; x1++, y1++;
        int x2, y2; cin >> x2 >> y2; x2++, y2++;
        str[x1].pb( {y1, y2} );
        fin[x2 - 1].pb( {y1, y2} );
    }

    int ans = 0;
    for(int i = 1; i <= N; i++){
        for(auto u: str[i]) seg.set(1, 1, N + 1, u.F, u.S, +1);
        for(auto u: fin[i - 1]) seg.set(1, 1, N + 1, u.F, u.S, -1);
        ans += N - mini[1].S;
    }

    cout << ans << endl;

}