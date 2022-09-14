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

const ll LIMIT = 2e9; 

int main (void)
{
    ll n, m; cin >> n >> m;
    ll x = n - m;

    if(m >= n) { cout << n; return 0; }

    ll L = 0, R = LIMIT;
    while (L < R) {
        ll MID = (L + R) / 2;
        ll sum = MID * (MID + 1) / 2;

        if (sum >= x) R = MID;
        elif(sum < x) L = ++MID;
    }
    cout << L + m << endl;
}