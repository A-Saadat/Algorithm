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
const int sq = 320;

int a[MAX]; 
deque<int> dq[320];
int cnt[320][MAX];
int n; 
int last = 0;

struct SQRT{
    
    void build(){
        for(int i = 0; i < n; i++) cnt[i / sq][a[i]]++;
    }

    void insertion(int l, int r){
        auto it1 = dq[r / sq].begin() + r % sq;
        int v = *it1; dq[r / sq].erase(it1); cnt[r / sq][v]--;

        auto it2 = dq[l / sq].begin() + l % sq;
        dq[l / sq].insert(it2, v); cnt[l / sq][v]++;
    }

    void update(int l, int r){
        insertion(l, r);
        for(int i = l - (l % sq); i <= r; i += sq){
            if(i + sq > r) break;
            int v = dq[i / sq].back(); dq[i / sq].pop_back(); cnt[i / sq][v]--;
            dq[(i / sq) + 1].push_front(v); cnt[(i / sq) + 1][v]++;
        }
    }

    int get(int l, int r, int k){
        int c = 0;
        for(int i = l; i <= r;){
            if(i % sq != 0 || i + sq > r){
                c += (dq[i / sq][i % sq] == k);
                i++;
            } 
            else c += cnt[i / sq][k], i += sq;
        }

        return c;
    }

} sqr;

main()
{IOS;

    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i], dq[i / sq].pb(a[i]);

    sqr.build();

    int q; cin >> q;
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int l, r; cin >> l >> r;
            l = ((l + (last - 1)) % n) + 1;
            r = ((r + (last - 1)) % n) + 1;
            --l; --r;
            if(l > r) swap(l, r);

            sqr.update(l, r);
        }
        else{
            int l, r, k; cin >> l >> r >> k;
            l = ((l + (last - 1)) % n) + 1;
            r = ((r + (last - 1)) % n) + 1;
            k = ((k + (last - 1)) % n) + 1;
            if(l > r) swap(l, r);

            --l; --r;
            last = sqr.get(l, r, k);
            cout << last << endl;
        }
    }

}