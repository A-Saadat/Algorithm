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
// #define int long long 

const int MAX = 1e5 + 10; 
const int INF = 1e9 + 7; 

struct Query{int l; int r; int idx;};

vector<int> a(MAX), b(MAX);
int n, q; 
vector<Query> que;

struct nod{
    pair<int, int> last, lazy, sum;
    // nod(){
    //     last = {0,0};
    //     lazy = {0,0};
    //     sum = {0,0};
    // }
} tree[(MAX << 2)];


struct Segment{
    void build(int id = 1, int l = 1, int r = n + 1){
        if(l + 1 == r){
            tree[id].sum = {0, b[l]};
            tree[id].last = {0, 0};
            tree[id].lazy = {0, 0};
            return;
        }

        int mid = (r + l) >> 1, lc = 2 * id + 0, rc = 2 * id + 1;
        build(lc, l, mid);
        build(rc, mid, r);

        tree[id].sum = {0, tree[lc].sum.S + tree[rc].sum.S};
        cout << id << ": [" << l << ", " << r << "] -> " << tree[id].sum.S << endl;
    }

    void push(int id){
        int lc = (id << 1), rc = lc | 1;
        tree[lc].lazy = max(tree[lc].lazy, tree[id].lazy);
        tree[rc].lazy = max(tree[rc].lazy, tree[id].lazy);
        tree[lc].last = max(tree[lc].last, tree[id].lazy);
        tree[rc].last = max(tree[rc].last, tree[id].lazy);
        tree[id].lazy = {0, 0};
    }

    void set(int id, int L, int R, int l, int r, int idx, int val){
        if(L == l && R == r){
            tree[id].last = {idx, val};
            tree[id].lazy = {idx, val};
            tree[id].sum = {idx, (R - L) * val};
            // cout << id << ": -> [" << L << ", " << R - 1 << "] = {" << tree[id].sum.F << ", " << tree[id].sum.S << "}\n";
            return;
        }

        push(id);
        int mid = (R + L) >> 1, lc = 2 * id + 0, rc = 2 * id + 1;
        if(l < mid)
            set(lc, L, mid, l, min(r, mid), idx, val);
        if(r > mid)
            set(rc, mid, R, max(l, mid), r, idx, val);

        tree[id].sum = {idx, tree[lc].sum.S + tree[rc].sum.S};

        // cout << id << ": -> [" << L << ", " << R - 1 << "] = {" << tree[id].sum.F << ", " << tree[id].sum.S << "}\n";
    }

    int get(int id, int L, int R, int l, int r){
        if(L == l && R == r){
            if(tree[id].last.F >= tree[id].sum.F) return ((R - L) * tree[id].last.S);
            else return tree[id].sum.S;
        }

        push(id);
        int mid = (R + L) >> 1, lc = 2 * id + 0, rc = 2 * id + 1, ret1 = 0, ret2 = 0;
        if(l < mid)
            ret1 = get(lc, L, mid, l, min(r, mid));
        if(r > mid)
            ret2 = get(rc, mid, R, max(l, mid), r);

        return ret1 + ret2;
    }

} seg;

bool check(int mid){
    for(int i = 1; i <= n; i++) b[i] = (mid <= a[i]);
    // for(int i = 1; i <= n; i++) cout << b[i] << " ";
    // cout << endl;
    seg.build();
    for(auto u: que){
        // cout << "[" << u.l << ", " << u.r << "] -> " << u.idx << endl;
        int L = u.l, R = u.r, idx = u.idx;
        if(L > R){
            swap(L, R); R++;
            int cnt = seg.get(1, 1, n + 1, L, R);
            // cout << "cnt = " << cnt << endl;
            seg.set(1, 1, n + 1, L, L + cnt, idx, 1);
            seg.set(1, 1, n + 1, L + cnt, R, idx, 0);
            // cout << "\n---------------\n";
        }
        else{
            R++;
            int cnt = seg.get(1, 1, n + 1, L, R);
            int lim = R - L - cnt;
            // cout << "cnt = " << cnt << " lim = " << lim << endl;
            seg.set(1, 1, n + 1, L, L + lim, idx, 0);
            seg.set(1, 1, n + 1, L + lim, R, idx, 1);
            // cout << "\n---------------\n";
        }
    }

    return seg.get(1, 1, n + 1, (n + 1) / 2, ((n + 1) / 2) + 1);

    // cout << seg.get(1, 1, n + 1, (n + 1) / 2, ((n + 1) / 2) + 1) << endl;
}

main()
{IOS;

    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= q; i++){
        int l, r; cin >> l >> r;
        que.pb( {l, r, i} );
    }

    // int L = 1, R = n + 1;
    // while(R - L > 1){
    //     int mid = (R + L) >> 1;
    //     if(check(mid)) L = mid;
    //     else R = mid;
    // }

    // cout << L << endl;

    // for(int i = 1; i <= 2; i++){
    //     cout << i << ": "  << check(i) << endl;

    // }

    cout << check(4) << endl;
    cout << "\n-------------------\n";
    cout << check(3) << endl;

}