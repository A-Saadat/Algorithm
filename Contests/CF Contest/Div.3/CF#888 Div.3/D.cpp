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

const int MAX = 1e6; 
const int INF = 1e9 + 7; 

ll a[MAX];
vector<ll> vv, s; 
map<int, int> mp;

main()
{IOS;

    int t; cin >> t;
    while(t--){
        int n; cin >> n;

        bool isOnce = 0, isOk = 1; ll imp = 0;
        for(int i = 1; i < n; i++) cin >> a[i];
        for(int i = 1; i < n; i++){
            ll x = a[i] - a[i - 1];
            vv.pb(x);
            mp[x]++;
            if(x > n) isOnce = 1, imp = x;
            elif(isOnce && x > n) isOk = 0;
        }

        if(!isOnce){
            int sz1 = vv.size();
            uni(vv);
            int sz2 = s.size();

            if(sz1 - sz2 != 1) isOk = false; 
        }

        if(!isOk) { cout << "NO\n"; continue; }

        int id = 0;
        fort(itr, mp){
            ++id;
            if(itr->F != id && itr->F <= n) s.pb(id), id = itr->F;
            if(itr->S == 2) imp = itr->F;
            // cout << itr->F << ' ' << itr->S << endl;
        } 

        if(!mp[n]) s.pb(n);

        int sz = s.size();
        // for(int u: s) cout << u << ' ';
        if(sz != 2) isOk = false;
        if(s[0] + s[1] != imp) isOk = false;


        if(isOk) cout << "YES\n";
        else cout << "NO\n";

    }

}