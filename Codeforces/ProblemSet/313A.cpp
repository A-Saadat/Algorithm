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


int main (void)
{
    ll n; cin >> n;
    if(n > 0){
        ll a = n / 10;
        ll rem = n % 10;
        ll b = ((n / 100) * 10) + rem;

        ll t = max(a, b);
        cout << max(t, n);
    }
    elif(n < 0){
        n *= -1;

        ll a = n / 10;
        ll rem = n % 10;
        ll b = ((n / 100) * 10) + rem;

        ll t = min(a, b);
        cout << min(t, n) * -1;   
    }
}