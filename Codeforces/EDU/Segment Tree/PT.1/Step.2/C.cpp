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

const int MAX = 1e6; 
const int INF = 1e9 + 7; 

int a[MAX]; 

struct Segment{
    int maxi[4 * MAX];

    void build(int id, int l, int r){
        if(l + 1 == r){
            maxi[id] = a[l];
            return;
        }

        int mid = (r + l) >> 1;
        build(2 * id + 0, l, mid); 
        build(2 * id + 1, mid, r);

        maxi[id] = max(maxi[2 * id + 0], maxi[2 * id + 1]); 
    }

    void set(int id, int l, int r, int idx, int val){
        if(l + 1 == r){
            maxi[id] = val;
            a[idx] = val;
            return;
        }

        int mid = (r + l) >> 1;
        if(idx < mid)
            set(2 * id + 0, l, mid, idx, val);
        else    
            set(2 * id + 1, mid, r, idx, val);

        maxi[id] = max(maxi[2 * id + 0], maxi[2 * id + 1]);
    }

    int get(int id, int l, int r, int x){
        if(l + 1 == r){
            if(maxi[id] >= x) return l;
            else return -1;
        }
        
        int mid = (r + l) >> 1;
        if(maxi[2 * id + 0] >= x)
            return get(2 * id + 0, l, mid, x);
        elif(maxi[2 * id + 1] >= x)
            return get(2 * id + 1, mid, r, x);
        else
            return -1;
    }
};

Segment seg;

main()
{IOS;

    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    seg.build(1, 1, n + 1);

    while(q--){
        int t; cin >> t;
        if(t == 1){
            int idx, val; cin >> idx >> val; ++idx;
            seg.set(1, 1, n + 1, idx, val);
        }
        else{
            int x; cin >> x;
            int ans = seg.get(1, 1, n + 1, x);
            cout << ans + (ans == -1 ? 0 : -1) << endl;
        }
    }

}