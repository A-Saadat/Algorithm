// 57 54 46 
#include <bits/stdc++.h> 
using namespace std; 

#define forn(i,k,n) for(int i = k; i < n; i++) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define IOS ios_base::sync_with_stdio(false) 
#define pb push_back 
#define F first 
#define S second 
#define mp make_pair 
#define gcd __gcd 
#define elif else if 
typedef long long int ll; 
typedef map<string, int> msi;  
typedef map<char, int> mci; 
typedef map<ll, ll> mll; 
typedef set<int> si;  
typedef int64_t i64; 
typedef vector<ll> vci;
typedef pair<int,int> pii; 
typedef vector<pii> vpii; 
typedef vector<string> vs; 
typedef vector<bool> vb; 
typedef vector<double> vd; 
typedef vector<char> vcc; 

const ll def = 1e6; 
const ll INF = 1e9 + 7; 
const char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

ll a[def]; 

main ()
{IOS;

    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        forn(i,1,(n + 1)) cin >> a[i];

        bool isPostive = (a[1] > 0 ? true : false);
        ll L = 1, R = 1, l = 1, r = 1, cnt = 1;
        forn(i,2,n + 1){
            isPostive = !isPostive;

            if((isPostive && a[i] > 0) || (!isPostive && a[i] < 0)) r++;
            else l = r, isPostive = (a[i] > 0 ? true : false);

            cout << l << ' ' << r << endl;

        }

        // cout << L << ' ' << R;
    }

}