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
#define err(x) cout << '#' << x << ':' << ' ' << x << endl 
typedef long long int ll; 
typedef vector<int> vi;

const int MaxN = 1e6; 
const int MOD = 1e9 + 7; 

int a[MaxN]; 

main()
{IOS;

    int t; cin >> t;
    while(t--){
        int ans = 1;
        
        int xa, xb, xc; 
        int ya, yb, yc;

        cin >> xa >> ya;
        cin >> xb >> yb;
        cin >> xc >> yc;

        if(xb - xa > 0 && xc - xa > 0)
            ans += min(xb - xa, xc - xa);

        if(xb - xa < 0 && xc - xa < 0)
            ans += -1 * max(xb - xa, xc - xa);

        if(yb - ya > 0 && yc - ya > 0)
            ans += min(yb - ya, yc - ya);

        if(yb - ya < 0 && yc - ya < 0)
            ans += -1 * max(yb - ya, yc - ya);


        cout << ans << endl;
    }

}