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

vci Merge(ll x[], ll sizeX, vpii y, ll sizeY);
bool Solve(vci ans, ll k);

ll Home[def]; 
vpii Shop, ShopMid;
vci AUTH;

int main (void)
{IOS;

    ll n, m, k; cin >> n >> m >> k;
    forn(i,0,n) cin >> Home[i];
    forn(i,0,m){
        ll x; cin >> x;
        Shop.pb(mp(x, i));
    }
    sort(Home, Home + n), sort(Shop.begin(), Shop.end());

    // codeStarts

    ll L = -1, R = m + 1;
    while(R - L > 1){
        ShopMid.clear();

        ll MID = (R + L) / 2;
        forn(i,m - MID,m)
            ShopMid.pb(Shop[i]);

        AUTH = Merge(Home, n, ShopMid, MID);
        bool isOk = Solve(AUTH, k);

        if(isOk) L = MID;
        else R = MID;
    }
    cout << L << endl;
    sort(ShopMid.begin(), ShopMid.end(), greater<pii>());
    forn(i,0,L) cout << ShopMid[i].S + 1 << ' ';

}

vci Merge(ll x[], ll sizeX, vpii y, ll sizeY){
    vci ans;
    ll p1 = 0, p2 = 0;
    ll siX = sizeX, siY = sizeY;

    while(siX > 0 && siY > 0){
        if(x[p1] < y[p2].F) ans.pb(x[p1]), p1++, siX--;
        else ans.pb(y[p2].F), p2++, siY--;
    }

    if(siX > 0)
        forn(i,p1,sizeX) ans.pb(x[i]);
    elif(siY)
        forn(i,p2,sizeY) ans.pb(y[i].F);

    return ans;
}

bool Solve(vci ans, ll k){
    ll DAY = 0; bool isOk = true;
    forn(i,0,ans.size()){
        // cout << "DAY -> " << ans[i] << ' ' << DAY << endl;

        if(ans[i] - DAY < 0) isOk = false;
        if((i + 1) % k == 0) ++DAY;
    }

    return isOk;
}