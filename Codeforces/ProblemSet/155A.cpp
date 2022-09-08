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

int main (void)
{
    ll n; cin >> n;
    ll a1; cin >> a1;

    ll max = a1, min = a1, ans = 0;
    forn(i,(n - 1)){
        ll x; cin >> x;

        if(x > max){
            ans++;
            max = x;
        }
        elif(x < min){
            ans++;
            min = x;
        }
    }

    cout << ans;
}