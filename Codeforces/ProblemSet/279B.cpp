#include <bits/stdc++.h> 
using namespace std; 

#define def 10000000 
#define forn(i,k,n) for(int i=k;i<n;i++) 
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
typedef int64_t i64; 
typedef vector<ll> vci;
typedef pair<int,int> pii; 
typedef vector<pii> vpii; 
typedef vector<string> vs; 
typedef vector<bool> vb; 
typedef vector<double> vd; 

typedef vector<char> vcc; 

const ll LIMIT = 1e8; 

const int maxn = 1e5 + 100;
int a[maxn];
int par[maxn];

int main (void)
{
    ll n, t;
    cin >> n >> t;

    forn(i,1,(n + 1)) cin >> a[i], par[i] = par[i - 1] + a[i];
    par[n + 1] = par[n];

    ll mx = 0;
    forn(i,1,(n + 1)){
        if(a[i] > t) continue;
        
        ll L = i;
        ll R = n + 1;

        while(R - L > 1)
        {
            ll MID = (L + R) / 2; 
            if(par[MID] - par[i - 1] <= t)
                L = MID;
            else    
                R = MID;
        }

        mx = max(mx, L - i + 1);
    }
    cout << mx;

}