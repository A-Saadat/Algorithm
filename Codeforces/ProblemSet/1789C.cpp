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

main()
{IOS;

    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        
        vector<int> last(n + m + 1, -1), cnt(n + m + 1, 0);
        for(int i = 1; i <= n; i++) cin >> a[i], last[ a[i] ] = 0;
        
        for(int i = 1; i <= m; i++){
            int p, v; cin >> p >> v;
            int f = a[p];

            cnt[f] += i - last[f];
            last[f] = -1;
            last[v] = i;
            a[p] = v;
        }

        for(int i = 1; i <= n + m; i++)
            cnt[i] += (last[i] < 0 ? 0 : m + 1 - last[i]);

        int ans = 0;
        int x = ((m + 1) * m) / 2;
        for(int i = 1; i <= n + m; i++){
            int y = (m + 1 - cnt[i]) * (m - cnt[i]) / 2;
            ans += x - y;
        }

        cout << ans << endl;
    }    

}