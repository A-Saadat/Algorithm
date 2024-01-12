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

struct nod{
    vector<pair<int, int>> v; // ? F = c, S = t
    vector<int> ps;
} tree[(MAX << 2)];

vector<int> adj[MAX];
int st[MAX], ft[MAX], dsc[MAX];
int n, root; 
pair<int, int> p[MAX];

int t = 0;
void dfs(int v, int p){
    st[v] = ++t, dsc[t] = v;
    for(int u: adj[v]){
        if(u == p) continue;
        dfs(u, v);
    }
    ft[v] = t;
}

struct Segment{

    void merge(int id, vector< pair<int, int> > A, vector< pair<int, int> > B){
        vector< pair<int, int> > res;
        vector<int> ps;

        int a = A.size(), b = B.size();
        int i = 0, j = 0;
        while(i != a && j != b){
            if(A[i].F > B[j].F) res.pb(B[j]), j++;
            elif(A[i].F < B[j].F) res.pb(A[i]), i++;
            else{
                if(A[i].S > B[i].S) res.pb(B[j]), j++;
                else res.pb(A[i]), i++;
            }
        }

        while(i != a) res.pb(A[i]), i++;
        while(j != b) res.pb(B[j]), j++;

        // for(auto u: res){
        //     cout << "{" << u.F << ", " << u.S << "} - ";
        // }
        // cout << endl;
        ps.pb(res[0].S);
        for(int i = 1; i < res.size(); i++){
            ps.pb(ps.back() + res[i].S);
        }
        // reverse(all(ps));

        // for(int u: ps)
        // for(int i = 0; i < ps.size(); i++){
        //     cout << "ps[" << i << "] = " << ps[i] << endl;
        //     // ps[i + 1] = ps[i] + res[i].t;
        // }
        // cout << "\n---------------\n";

        tree[id].v = res;
        tree[id].ps = ps;
    }

    void build(int id = 1, int l = 1, int r = n + 1){
        if(l + 1 == r){
            tree[id].v.pb({p[dsc[l]].F, p[dsc[l]].S});
            tree[id].ps.pb(p[dsc[l]].S);
            return;
        }

        int mid = (r + l) >> 1, lc = 2 * id + 0, rc = 2 * id + 1;
        build(lc, l, mid);
        build(rc, mid, r);

        merge(id, tree[lc].v, tree[rc].v);
        // cout << "[" << l << ", " << r - 1 << "]: ";
        // for(auto u: tree[id].v){
        //     cout << "{" << u.c << ", " << u.t << "} - ";
        // }
        // cout << endl;
        // for(int i = 0; i < tree[id].ps.size(); i++){
        //     cout << "ps[" << i << "] = " << tree[id].ps[i] << endl;
        // }
        // cout << "\n---------------\n";
    }

    int get(int id, int L, int R, int l, int r, int val){
        if(l >= r) return 0;
        if(L == l && R == r){
            int lim = lower_bound(all(tree[id].v), make_pair(val, 0)) - tree[id].v.begin();
            // cout << "[" << L << ", " << R << "] = " << lim << endl;
            if(lim <= 0) return 0;
            return tree[id].ps[lim - 1];
        }
        int mid = (R + L) >> 1, ret1 = 0, ret2 = 0, lc = 2 * id + 0, rc = 2 * id + 1;
        if(l < mid)
            ret1 = get(lc, L, mid, l, min(mid, r), val);
        if(r > mid)
            ret2 = get(rc, mid, R, max(l, mid), r, val);

        return ret1 + ret2;
    }

} seg;

int main()
{IOS;

    cin >> n;
    for(int i = 1; i <= n; i++){
        int par; cin >> par;
        if(par != -1) {
            adj[i].pb(par);
            adj[par].pb(i);
        }
        else root = i;
        cin >> p[i].F >> p[i].S;
    }

    dfs(root, 0);


    // vector< pair<int, int> > A = {{3, 80}, {10, 29}, {12, 3}};
    // vector< pair<int, int> > B = {{3, 20}, {8, 9}, {22, 30}};

    // seg.merge(1, A, B);

    // for(int i = 1; i <= n; i++) cout << dsc[i] << ' ';
    // cout << endl;
    seg.build();
    for(int i = 1; i <= n; i++){
        int l = st[i] + 1, r = ft[i] + 1;
        cout << seg.get(1, 1, n + 1, l, r, p[i].F) << endl;
        // cout << i << ": " <<  "[" << l << ", " << r << ")\n";
    }

}