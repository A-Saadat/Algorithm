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

ll a[def], powers[def]; 

main ()
{IOS;

    ll t; cin >> t;
    while(t--){

        ll n, k; cin >> n >> k;
        forn(i,0,n) cin >> a[i];
        sort(a, a + n, greater<ll>());

        // ? Find the Maximum power
        ll maxI = 0, tmp = a[0];
        while(tmp > 1){
            tmp /= k;
            maxI++;
        }

        // ? Find the Powers
        forn(i,0,maxI) powers[i] = 1;
        powers[0] = 1;
        forn(i,1,maxI + 1) powers[i] = powers[i - 1] * k;
        reverse(powers, powers + maxI + 1);

        forn(i,0,maxI + 1){
            bool isUsing = false;
            forn(j,0,n){
                if(a[j] >= powers[i] && !isUsing) a[j] -= powers[i], isUsing = true;
            }
        }

        bool isOk = true;
        forn(i,0,n) if(a[i]) isOk = false;

        if(isOk) cout << "YES" << endl;
        else cout << "NO" << endl;

    }

}