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
const int INF = 1e9 + 7; 

vector< pair<int, int> > a;
int b[MaxN], ans[MaxN]; 

main()
{IOS;

    int t; cin >> t;
    while(t--){
        a.clear();
        int n, k; cin >> n >> k;
        for(int i = 1; i <= n; i++){
            int x; cin >> x;
            a.pb( {x, i} );
        }

        for(int i = 1; i <= n; i++) cin >> b[i];

        sort( all(a) ); sort(b + 1, b + n + 1);

        for(int i = 0; i < n; i++)
            ans[ a[i].S ] = b[i + 1];

        for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
        cout << endl;
    }

}