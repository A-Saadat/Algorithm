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

const int MAX = 1e6; 
const int INF = 1e9 + 7; 

int a[MAX], b[MAX]; 
multiset<int> s;

main()
{IOS;

    int t; cin >> t;
    while(t--){
        s.clear();
        int n, m; cin >> n >> m;
        for(int i = 1; i <= n; i++) cin >> a[i], s.insert(a[i]);
        for(int i = 1; i <= m; i++){
            cin >> b[i];
            s.erase(s.begin());
            s.insert(b[i]);
        } 

        int ans = 0;
        fort(itr, s) ans += *itr;
        cout << ans << endl;

    }

}