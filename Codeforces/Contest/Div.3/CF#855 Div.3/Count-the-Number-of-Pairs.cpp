// 57 54 46 
#include <bits/stdc++.h> 
using namespace std; 

#define forn(i,k,n) for(int i = k; i < n; i++) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0); 
#define pb push_back 
#define F first 
#define S second 
#define gcd __gcd 
#define elif else if 
#define all(v) v.begin(), v.end() 
#define uni(v) sort(all(v)), v.erase(unique(all(v)), v.end()) 
#define err(x) cout << '#' << x << ':' << ' ' << x << endl 
typedef long long int ll; 
typedef vector<int> vi;

const ll MaxN = 1e6; 
const ll INF = 1e9 + 7; 

int a[MaxN]; 
map<char, int> mp;

main()
{IOS;

    int t; cin >> t;
    while(t--){
        mp.clear();

        int n, k; cin >> n >> k;
        forn(i,0,n){
            char c; cin >> c;
            mp[c]++;
        }

        int ans = 0;

        forn(i,1,27){
            char a = (char)(i + 64);
            char b = (char)(i + 96);
            
            if(!mp[a] && !mp[b]) continue;
            ans += min(mp[a], mp[b]);
            
            int S = abs(mp[a] - mp[b]);

            if(!k) continue;

            if((S / 2) < k) ans += (S / 2), k -= (S / 2);
            elif((S / 2) >= k) { ans += k; k = 0; }
        }

        cout << ans << endl;
    }

}