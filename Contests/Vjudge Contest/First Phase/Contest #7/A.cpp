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

const int MAX = 1e2 + 10; 
const int INF = 1e9 + 7; 

int a[MAX], b[MAX]; 

inline void solve(){
    vector<pair<int, int>> ans;
    int n; cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];

    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            if(a[j] < a[i]){
                swap(a[i], a[j]);
                swap(b[i], b[j]);
                ans.pb({i, j});
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            if(b[j] < b[i]){
                swap(a[i], a[j]);
                swap(b[i], b[j]);
                ans.pb({i, j});
            }
        }
    }

    bool isOk = 1;
    for(int i = 1; i < n; i++) 
        if(a[i] > a[i + 1] || b[i] > b[i + 1]) isOk = 0;

    if(isOk){
        cout << ans.size() << endl;
        for(auto u: ans) cout << u.F << ' ' << u.S << endl;
    }
    else cout << "-1\n";
}

main()
{IOS;

    int t; cin >> t;
    while(t--) solve();  

}