// 57 54 46 
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

vci findPrime(int x){
    bool notPrime[def];
    vci primeNum;

    for(ll i = 2; i <= x; i++){
        for(ll j = i * i; j <= x; j+=i){
            notPrime[j] = true;
        }
    }
    forn(i,0,x) if(!notPrime[i]) primeNum.pb(i);

    return primeNum;
}

vci prime;
vci ans;

int main (void)
{IOS;

    ll n, k; cin >> n >> k;
    prime = findPrime(n);

    forn(i,2,prime.size()){
        ll cnt = 0;

        // while(n > 0){

        //     n /= prime[i]; cnt++;

        //     // n /= prime[i];
        //     // ans.pb(prime[i]);
        //     // ++cnt;

        //     // if(cnt == k - 1){


        //     //     forn(i,0,(k - 1)) cout << ans[i] << ' ';
        //     //     cout << n << endl;

        //     // }

        // }

        cout << prime[i] << ' ' << cnt << endl;
            // cout << n << ' ';
        
    }


}