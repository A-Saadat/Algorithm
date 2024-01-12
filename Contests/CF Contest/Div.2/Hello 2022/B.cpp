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

int a[MAX]; 
struct seg{int l; int r; int c;};

main()
{IOS;

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        
        seg low = {INF, INF, INF}, hig = {-INF, -INF, INF};
        for(int i = 1; i <= n; i++){
            int res = INF;
            int l, r, c; cin >> l >> r >> c;
            
            if(l < low.l) low = {l, r, c};
            if(r > hig.r) hig = {l, r, c};
            
            if(l == low.l && c < low.c) low = {l, r, c};
            if(r == hig.r && c < hig.c) hig = {l, r, c};

            if(low.l == hig.l){
                if(low.r > hig.r) res = min(res, low.c);
                elif(low.r < hig.r) res = min(res, hig.c);
            } 
            if(low.r == hig.r){
                if(low.l < hig.l) res = min(res, low.c);
                elif(low.l > hig.l) res = min(res, hig.c);
            }
            if(low.l == hig.l && low.r == hig.r) res = min({res, hig.c, low.c});
            res = min(res, hig.c + low.c);

            cout << res << endl;
        }
    }

}