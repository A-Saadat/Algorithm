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
vector<int> v;

main()
{IOS;

    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        for(int i = 0; i < n; i++) cin >> a[i];

        int sum = 0;
        for(int i = 1; i < n; i++){
            int x = abs(a[i - 1] - a[i]);
            
            v.pb( x );
            sum += x;
        }

        sort(all(v), greater<int>());

        for(int i = 0; i < k - 1; i++) sum -= v[i];

        v.clear();

        cout << sum << endl;
    }

}