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
typedef vector<int> vi;

const int MAX = 2e5 + 10; 
const int INF = 1e9 + 7; 

vector< pair<int, int> > v; 
int a[MAX], mark[MAX];
int ans, cnt, n, p;

inline void _union(int v, int val){
    mark[v] = 1;
    for(int i = v + 1; i <= n; i++){
        if(a[i] % val) break;
        if(mark[i]){
            ans += val;
            cnt++;
            mark[i] = 1;
            break;
        }
        ans += val;
        cnt++;
        mark[i] = 1;
    }
    for(int i = v - 1; i > 0; i--){
        if(a[i] % val) break;
        if(mark[i]){
            ans += val;
            cnt++;
            mark[i] = 1;
            break;
        }
        ans += val;
        cnt++;
        mark[i] = 1;
    }
}

inline void clearArr(){
    ans = 0, cnt = 0;
    memset(mark, 0, sizeof(mark));
    v.clear();
}

main()
{IOS;

    int t; cin >> t;
    while(t--){
        clearArr();
        
        cin >> n >> p;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            v.pb( {a[i], i} );
        } 
        sort(all(v));
        for(auto u: v){
            if(mark[u.S]) continue;
            if(u.F >= p) break;
            _union(u.S, u.F);
        }
        ans += (n - cnt - 1) * p;
        cout << ans << endl;
    }    

}