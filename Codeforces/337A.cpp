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

const ll LIMIT = 1e5; 
ll a[def];

int main (void)
{
    ll n, m; cin >> n >> m;
    forn(i,1,def){
        a[i] = LIMIT;
    }

    forn(i,1,(m + 1)) cin >> a[i];
    sort(a + 1, a + m + 1);

    ll mini = a[n] - a[1];
    forn(i,1,m+1){
        mini = min(mini, a[i + m] - a[i]);
        cout << a[i] << ' ' << a[i + m - 1] << endl;
    }

    // cout << mini;
}