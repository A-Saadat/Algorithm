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
const char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

vci findPrime(int x){
    bool notPrime[def];
    vci primeNum;

    for(ll i = 2; i * i <= x; i++){
        for(ll j = i * i; j <= x; j+=i){
            notPrime[j] = true;
        }
    }
    forn(i,2,x) if(!notPrime[i]) primeNum.pb(i);

    return primeNum;
}

vci Prime, ans;

int main (void)
{IOS;

    ll n, k; cin >> n >> k;

    ll cnt = 1, i = 2;
    while(i < n && cnt < k){
        while(n % i == 0 && cnt < k && n > 0 && n != i) n /= i, cnt++, ans.pb(i);
        ++i;
    }

    if(cnt < k){
        cout << -1;
        return 0;
    }

    forn(i,0,k - 1) cout << ans[i] << ' ';
    cout << n;

}