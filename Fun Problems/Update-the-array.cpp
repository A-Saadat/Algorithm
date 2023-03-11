// 57 54 46 
#include <bits/stdc++.h> 
using namespace std; 

#define forn(i,k,n) for(int i = k; i < n; i++) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0); 
#define pb push_back 
#define F first 
#define S second 
#define mp make_pair 
#define gcd __gcd 
#define bp __builtin_popcount 
#define elif else if 
#define all(v) v.begin(), v.end() 
#define uni(v) sort(all(v)), v.erase(unique(all(v)), v.end()) 
#define err(x) cout << '#' << x << ':' << ' ' << x << endl 
typedef long long int ll; 
typedef map<ll, ll> mll; 
typedef set<int> si;  
typedef pair<ll,ll> pii; 
typedef vector<ll> vci;
typedef vector<pii> vpii; 
typedef vector<string> vs; 
typedef vector<char> vcc; 

const ll MaxN = 1e6; 
const ll INF = 1e9 + 7; 

int a[MaxN], sum[MaxN]; 

main()
{IOS;

    int t; cin >> t;
    while(t--){
        int n, u; cin >> n >> u;
        cout << "\n-------\n";
        forn(i,0,u){
            int l, r, val; cin >> l >> r >> val;
            a[l] += val, a[r + 1] += -val;
            // cout << "\n-------\n";
        }

        forn(i,0,n) sum[i] = sum[i - 1] + a[i];

        int q; cin >> q;
        while(q--){
            int x; cin >> x;
            cout << sum[x] << endl;
        }
    }


}