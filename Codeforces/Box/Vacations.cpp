// 57 54 46 --> WTF
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

const ll MaxN = 1e3; 
const ll INF = 1e9 + 7; 

ll a[MaxN], dp[MaxN][MaxN]; 

// ? 1: Gym
// ? 2: Contest


main()
{IOS;

    ll n; cin >> n;
    forn(i,1,n + 1) cin >> a[i];

    dp[1][0] = 1;
    if(a[1] == 1 || a[1] == 3) dp[1][1] = 0;
    else dp[1][1] = INF;

    if(a[1] == 2 || a[1] == 3) dp[1][2] = 0;
    else dp[1][2] = INF;

    forn(i,2,n + 1){
        dp[i][0] = dp[i - 1][0] + 1;
         
        if(a[i] == 1 && a[i - 1] == 1) dp[i][1] = dp[i - 1][1] + 1;
        if(a[i] == 2 && a[i - 1] == 2) dp[i][2] = dp[i - 1][2] + 1;

    }

}