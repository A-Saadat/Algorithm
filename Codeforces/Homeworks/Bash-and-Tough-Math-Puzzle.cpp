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

const int MAX = 5e5 + 10; 
const int INF = 1e9 + 7; 

int a[MAX], gc[(MAX << 2)]; 
struct nod{int id; int l; int r;};
vector<nod> bad;
int n; 

struct Segment{
    void build(int id = 1, int l = 1, int r = n + 1){
        if(l + 1 == r){
            gc[id] = a[l];
            return;
        }
        int mid = (l + r) >> 1, lc = 2 * id + 0, rc = 2 * id + 1;
        build(lc, l, mid);
        build(rc, mid, r);

        gc[id] = __gcd(gc[lc], gc[rc]);
    }
    
    void set(int id, int l, int r, int idx, int val){
        if(l + 1 == r){
            a[idx] = val;
            gc[id] = val;
            return;
        }
        int mid = (l + r) >> 1, lc = 2 * id + 0, rc = 2 * id + 1;
        if(idx < mid)   
            set(lc, l, mid, idx, val);
        else    
            set(rc, mid, r, idx, val);

        gc[id] = __gcd(gc[lc], gc[rc]);
    }

    void get(int id, int l, int r, int tl, int tr, int x){
        if(tl == l && tr == r){
            if((gc[id] % x)) bad.pb({id, l, r});
            return;
        }
        int mid = (l + r) >> 1, lc = 2 * id + 0, rc = 2 * id + 1;
        if(tl < mid)
            get(lc, l, mid, tl, min(tr, mid), x);
        if(tr > mid)
            get(rc, mid, r, max(mid, tl), tr, x);
    }

    bool get2(int id, int l, int r, int x){
        if(l + 1 == r) return 1;

        int mid = (l + r) >> 1, lc = 2 * id + 0, rc = 2 * id + 1;
        if((gc[lc] % x) && (gc[rc] % x)) return 0;
        elif(gc[lc] % x) return get2(lc, l, mid, x);
        else return get2(rc, mid, r, x);
    }

} seg;

main()
{IOS;

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    seg.build();
    int q; cin >> q;
    while(q--){
        int type; cin >> type;
        if(type == 1){
            bad.clear();
            int l, r, x; cin >> l >> r >> x; ++r;
            seg.get(1, 1, n + 1, l, r, x);
            
            if(bad.size() == 0) cout << "YES\n";
            elif(bad.size() > 1) cout << "NO\n";
            else{
                int id = bad.back().id, l = bad.back().l, r = bad.back().r;
                cout << (seg.get2(id, l, r, x) ? "YES" : "NO") << endl;
            }
        }
        else{
            int idx, val; cin >> idx >> val;
            seg.set(1, 1, n + 1, idx, val);
        }
    }

}