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

int main (void)
{
    ll n; cin >> n;
    ll mishkaCnt = 0, chrisCnt = 0;
    forn(i,0,n){
        ll m, c; cin >> m >> c;
        if(m > c) mishkaCnt++;
        elif(m < c) chrisCnt++;
    }

    if(mishkaCnt > chrisCnt) cout << "Mishka";
    elif(mishkaCnt < chrisCnt) cout << "Chris";
    else cout << "Friendship is magic!^^";
}