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

const int MAX = 2e5 + 10; 
const int INF = 1e9 + 7; 

int a[MAX], cyc[MAX]; 
int n; 

inline void Solve(){
    int cnt = 1, ans = 0;
    for(int i = 1; i <= n; i++){
        if(cyc[i]) continue;

        int v = i;
        while(!cyc[v]){
            cyc[v] = cnt;
            v = a[v];
            ans++;
        }

        ans--, cnt++;
    }

    for(int i = 1; i < n; i++){
        if(cyc[i] == cyc[i + 1]) {
            cout << ans - 1 << endl;
            return;
        }
    }

    cout << ans + 1 << endl;
}

main()
{IOS;

    int t; cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n; i++) cyc[i] = 0;
        Solve();
    }

}