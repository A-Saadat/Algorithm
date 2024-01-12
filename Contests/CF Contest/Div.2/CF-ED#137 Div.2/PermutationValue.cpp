#include <bits/stdc++.h> 
using namespace std; 

#define def 10000000 
#define forn(i,k,n) for(int i = k; i < n; i++) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define IOS ios_base::sync_with_stdio(false) 
#define msi map<string, int> 
#define mci map<char, int> 
#define mll map<ll, ll> 
#define si set<int> 
#define pb push_back 
#define F first 
#define S second 
#define mp make_pair 
#define gcd __gcd 
#define elif else if 
typedef long long int ll; 
typedef int64_t i64; 
typedef vector<ll> vci;
typedef pair<int,int> pii; 
typedef vector<pii> vpii; 
typedef vector<string> vs; 
typedef vector<bool> vb; 
typedef vector<double> vd; 
typedef vector<char> vcc; 

const ll LIMIT = 1e8; 
const char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

ll a[def];

int main (void)
{IOS;

    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        if(n == 3) cout << "1 3 2" << endl;
        else{
            
            ll m = n % 2 == 0 ? n / 2 : (n + 1) / 2;
            ll idx = 1;
            for(ll i = 0; idx <= m; i +=2 ) a[i] = idx, idx++;

            for(ll i = 1; idx <= n; i +=2 ) a[i] = idx, idx++;  

            if(n % 2 == 0){
                ll tmp = a[n - 1];
                a[n - 1] = a[n - 2];
                a[n - 2] = tmp;
            }

            forn(i,0,n) cout << a[i] << ' ';
            cout << endl;
        }
    }

}