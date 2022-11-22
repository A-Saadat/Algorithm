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

main ()
{IOS;

    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        ll tmp = n;

        ll a = 0;
        for(ll i = 2; i * i <= n; i++)
            if(n % i == 0) { a = i; break; }

        if(!a) { cout << "NO" << endl; continue; }
         
        tmp /= a;

        ll b = 0;
        for(ll i = 2; i * i <= tmp; i++){
            if(tmp % i == 0 && i > a) { b = i; break; }
        }

        if(!b) { cout << "NO" << endl; continue; }

        ll c = n / (a * b);
        ll ans = a * b * c;
        
        if(ans != n || a == c || b == c) { cout << "NO" << endl; }
        else cout << "YES" << endl << a << ' ' << b << ' ' << c << endl; 
    }   


}