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
#define all(v) v.begin(), v.end() 
#define uni(v) sort(all(v)), v.erase(unique(all(v)), v.end()) 
#define scan(a, n) for(int i = 0; i < n; i++) cin >> a[i]; 
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
bool notPrime[def];

void findPrime(ll x){
    for(ll i = 2; i * i <= x; i++){
        for(ll j = i * i; j <= x; j += i){
            notPrime[j] = true;
        }
    }
}

main ()
{IOS;
    findPrime(1e6);

    for(ll i = 2; i <= 1e6; i++){
        if(!notPrime[i]){
            ++a[i];
            if(i * i <= 1e6) --a[i * i];
        }

        a[i] += a[i - 1];
    }

    int t; scanf("%d", &t);
    while(t--){
        int n; scanf("%d", &n);
        printf("%d\n", (a[n] + 1));
    }
 
}