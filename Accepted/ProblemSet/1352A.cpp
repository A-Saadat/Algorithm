#include <bits/stdc++.h> 
using namespace std; 

#define def 10000000 
#define forn(i,n) for(int i=0;i<n;i++) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define msi map<string, int> 
#define mci map<char, int> 
#define si set<int> 
#define pb push_back 
#define F first 
#define S second 
#define mp make_pair 
#define elif else if 
typedef long long int ll; 
typedef vector<ll> vci;
typedef pair<int,int> pii; 
typedef vector<pii> vpii; 
typedef vector<string> vs; 
typedef vector<bool> vb; 
typedef vector<double> vd; 

ll myPow(ll x, ll y){
    ll ans = 1;
    while(y--){
        ans *= x;
    }

    return ans;
}

vpii a;

int main (void)
{
    ll t; cin >> t;

    while(t--){
        a.clear();
        ll n; cin >> n;

        ll idx = 0;
        while(n > 0){
            if(n % 10 != 0) a.pb(mp(idx, (n % 10)));

            n /= 10;
            idx++;
        }

        cout << a.size() << endl;
        forn(i,a.size()){
            cout << a[i].S * myPow(10, a[i].F) << ' ';
        } 

        cout << endl;
    }

}