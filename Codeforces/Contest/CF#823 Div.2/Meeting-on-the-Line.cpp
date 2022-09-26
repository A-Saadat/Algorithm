#include <bits/stdc++.h> 
using namespace std; 

#define def 10000000 
#define forn(i,k,n) for(int i = k; i < n; i++) 
#define forb(i,n,k) for(int i = (n - 1); i < k; i--) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define msi map<string, int> 
#define mci map<char, int> 
#define mll map<ll, ll> 
#define si set<int> 
#define pb push_back 
#define F first 
#define S second 
#define mp make_pair 
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
ll a[def]; 
ll ti[def];

int main (void)
{
    ll t; cin >> t;

    while(t--){
        ll n, maxi = 0; cin >> n;
        forn(i,0,n) cin >> a[i], maxi = max(maxi, a[i]);
        forn(i,0,n) cin >> ti[i];

        double L = -1, R = maxi;
        ll prevCost = 0, currCost = 0;

        forn(i,0,n) currCost += abs(a[i] - maxi) + ti[i];
        prevCost = currCost;

        while(true){
            currCost = 0;
            forn(i,0,n) currCost += abs(a[i] - maxi) + ti[i];

            cout << "Curr: " << currCost << " prev: " << prevCost << " -> Place: " << maxi << endl;

            if(prevCost < currCost) break;
            else prevCost = currCost;

            maxi--;
        }

        cout << maxi;
    }
}