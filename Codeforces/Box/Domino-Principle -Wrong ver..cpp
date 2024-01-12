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

map<int, int> idx;
vector<pair<int, int>> que;
vector<int> all;

struct Segment{
    vector<int> v[4 * MAX];

    vector<int> merge(vector<int> A, vector<int> B){
        vector<int> ans;
        int a = A.size(), b = B.size();
        int i = 0, j = 0;

        while(i < a && j < b){
            if(A[i] < B[j]) ans.pb(A[i]), i++;
            else ans.pb(B[j]), j++;
        }

        while(i < a) ans.pb(A[i]), i++;
        while(j < b) ans.pb(B[j]), j++;

        return ans;
    }

    void build(int id, int l, int r){
        if(l + 1 == r){
            v[id].pb(all[l - 1]);
            return;
        }

        int mid = (r + l) >> 1;
        build(2 * id + 0, l, mid);
        build(2 * id + 1, mid, r);

        v[id] = merge(v[2 * id + 0], v[2 * id + 1]);
    }

    int get(int id, int L, int R, int l, int r, int vL, int vR){
        if(l == L && R == r)
            return (lower_bound(all(v[id]), vR) - lower_bound(all(v[id]), vL));

        int mid = (R + L) >> 1;
        int ret1 = 0, ret2 = 0;
        if(l < mid)
            ret1 = get(2 * id + 0, L, mid, l, min(r, mid), vL, vR);
        if(r > mid)
            ret2 = get(2 * id + 1, mid, R, max(l, mid), r, vL, vR);

        return ret1 + ret2; 
    }
};

Segment seg;

main()
{IOS;

    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        int x, h; cin >> x >> h;
        all.pb(x);
        que.pb( {x, x + h} );
    }
    sort(all(all));
    for(int i = 0; i < all.size(); i++) idx[all[i]] = i + 1;
    seg.build(1, 1, n + 1);

    for(auto u: que){
        int vl = u.F, vr = u.S;
        cout << seg.get(1, 1, n + 1, idx[vL], n + 1, vL, vR) << ' ';
    }

}