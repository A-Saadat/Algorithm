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

const ll LIMIT = 1e3;

int main (void)
{
    ll k, r; cin >> k >> r;

    ll ans = LIMIT;
    forn(i,1,LIMIT){
        ll x = i * k;
        ll rem = x % 10;

        if(rem == 0 or rem == r){
            cout << i;
            return 0;
        }
    }
}