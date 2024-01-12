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
const int INF = 1e9 + 7; 

vector< pair<int, int> > seg;
vector< pair<int, int> > all;
int n, m, cnt, maxi; 

inline void Find_max(){
    sort(all(seg));
    cnt = 0;
    for(int i = 0; i < seg.size(); i++){
        if(seg[i].S == 0) cnt++; 
        else cnt--; 

        maxi = max(maxi, cnt);
    }
}

inline void clear_arr(){
    seg.clear();
    all.clear();
    maxi = 0;
    cnt = 0;
}

inline void Solve(){
    clear_arr();
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        int l, r; cin >> l >> r;
        all.pb( {l, r} );
    }

    for(int i = 0; i < n; i++){
        int l = all[i].F, r = all[i].S;
        if(l == 1) continue;

        seg.pb( {l, 0} );
        seg.pb( {r, 1} );
    }

    Find_max();
    seg.clear();

    for(int i = 0; i < n; i++){
        int l = all[i].F, r = all[i].S;
        if(l == m || r == m) continue;

        seg.pb( {l, 0} );
        seg.pb( {r, 1} );
    }

    Find_max();

    cout << maxi << endl;
}

main()
{IOS;

    int t; cin >> t;
    while(t--) Solve();    
}