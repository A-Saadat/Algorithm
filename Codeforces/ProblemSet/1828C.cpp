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
typedef vector<int> vi;

const int MAX = 2e5 + 10; 
const int MOD = 1e9 + 7; 

int b[MAX];
vector<int> a; 
long long ans = 1;

main()
{IOS;

    int t; cin >> t;
    while(t--){
        a.clear();
        memset(b, 0, sizeof(b));
        ans = 1;

        int n; cin >> n;
        for(int i = 1; i <= n; i++){
            int x; cin >> x;
            a.pb(x);
        }
        for(int i = 1; i <= n; i++) cin >> b[i];
        sort(all(a));
        sort(b + 1, b + n + 1, greater<int>());

        int cnt = -1;
        for(int i = 1; i <= n; i++){
            int ways = a.end() - upper_bound(all(a), b[i]);
            ways -= ++cnt;
            ans = (ans % MOD) * (ways % MOD) % MOD;
        }

        cout << ans << endl;
    }

}