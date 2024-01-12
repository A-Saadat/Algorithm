#include <bits/stdc++.h> 
using namespace std; 

#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0) 
#define forn(i,k,n) for(int i = k; i < n; i++) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define pb push_back 
#define elif else if 
#define F first 
#define S second 
#define gcd __gcd 
#define all(v) v.begin(), v.end() 
#define uni(v) sort(all(v)), v.erase(unique(all(v)), v.end()) 
typedef long long int ll; 
typedef vector<int> vi;

const int MAX = 5e4 + 1000; 
const int INF = 1e9 + 7; 

int mini = INF;
vector<int> a, v;

main()
{IOS;

    int t; cin >> t;
    while(t--){
        mini = INF; v.clear();
        int n; cin >> n;
        for(int i = 1; i <= n; i++){
            a.clear();
            int m; cin >> m;
            for(int j = 1; j <= m; j++) {
                int x; cin >> x;
                a.pb(x);
            }

            sort(all(a));

            mini = min(mini, a[0]);
            v.pb(a[1]);
        }


        ll ans = mini;
        sort(all(v), greater<int>());
        v.pop_back();
        for(int u: v) ans += u;

        cout << ans << endl;
    }

}