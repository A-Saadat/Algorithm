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

ll a[def];

int main (void)
{
    ll t; cin >> t;

    while(t--){
        ll n; cin >> n;
        forn(i,n) cin >> a[i];

        ll L = 0, R = a[n - 1];
        while(R - L > 1){
            ll MID = L + ((R - L) / 2);

            for(ll i = n - 1; i >= 2; i++){
                ll d = (a[i] - MID) / 3;

                if(MID > a[i]) break;

                a[i] -= (3 * d);
            }

        }
    }


}