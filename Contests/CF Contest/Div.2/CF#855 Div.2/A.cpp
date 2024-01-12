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

const int MAX = 1e2 + 100; 
const int INF = 1e9 + 7; 

main()
{IOS;

    int t; cin >> t;
    while(t--){
        int n, m, k; cin >> n >> m >> k;
        int x, y; cin >> x >> y;
        bool isOk = 1;
        while(k--){
            int a, b; cin >> a >> b;
            if( !((abs(x - a) + abs(y - b)) % 2)) isOk = 0;
        }

        if(isOk) cout << "YES\n";
        else cout << "NO\n";
    }    

}