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

inline bool Solve(){
    int x, d; cin >> x >> d;
    int cnt = 0;
    while(x % d == 0){
        cnt++;
        x /= d;
    }
    if(cnt == 1) return puts("NO");

    cout << cnt << endl;

    int ans = 1;
    for(int i = 2; i * i <= x; i++){
        int cc = 0;
        while(x % i == 0){
            cc++;
            x /= i;
        }
        ans = ans * (cc + 1);

        if(ans >= cnt + 1) return puts("YES");
    }

    return puts("NO");

    // cout << cnt << endl;
}

signed main()
{IOS;

    int t; cin >> t;
    while(t--){
        Solve();
    }

}