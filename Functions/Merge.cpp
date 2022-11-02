// 57 54 46 
#include <bits/stdc++.h> 
using namespace std; 

#define forn(i,k,n) for(int i = k; i < n; i++) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define IOS ios_base::sync_with_stdio(false) 
#define pb push_back 
#define F first 
#define S second 
#define mp make_pair 
#define gcd __gcd 
#define elif else if 
typedef long long int ll; 
typedef map<string, int> msi;  
typedef map<char, int> mci; 
typedef map<ll, ll> mll; 
typedef set<int> si;  
typedef int64_t i64; 
typedef vector<ll> vci;
typedef pair<int,int> pii; 
typedef vector<pii> vpii; 
typedef vector<string> vs; 
typedef vector<bool> vb; 
typedef vector<double> vd; 
typedef vector<char> vcc; 

const ll def = 1e6; 
const char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

vci Merge(ll x[], ll sizeX, ll y[], ll sizeY){
    vci ans;
    ll p1 = 0, p2 = 0;
    ll siX = sizeX, siY = sizeY;

    while(siX > 0 && siY > 0){
        if(x[p1] < y[p2]) ans.pb(x[p1]), p1++, siX--;
        else ans.pb(y[p2]), p2++, siY--;
    }

    if(siX > 0)
        forn(i,p1,sizeX) ans.pb(x[i]);
    elif(siY)
        forn(i,p2,sizeY) ans.pb(y[i]);

    return ans;
}

int main (void)
{IOS;

    

}