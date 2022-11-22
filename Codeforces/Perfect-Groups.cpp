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
typedef set<ll> si;  
typedef int64_t i64; 
typedef vector<ll> vci;
typedef pair<int,int> pii; 
typedef vector<pii> vpii; 
typedef vector<string> vs; 
typedef vector<bool> vb; 
typedef vector<double> vd; 
typedef vector<char> vcc; 

const ll def = 1e6; 
const ll INF = 1e9 + 7; 
const char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

ll a[def], Mark[def], ans[def]; 

void Compress(ll n){
    vci v;
    forn(i,1,(n + 1)) v.pb(a[i]);
    sort(v.begin(), v.end());

    auto ip = unique(v.begin(), v.end());
    v.resize(distance(v.begin(), ip));

    forn(i,1,(n + 1))
        if(a[i]) a[i] = (lower_bound(v.begin(), v.end(), a[i]) - v.begin()) + 1;
}

main ()
{IOS;

    ll n; cin >> n;
    forn(i,1,(n + 1)) cin >> a[i];

    forn(i,1,(n + 1)){
        ll x = a[i];
        bool flag = false;
        if(a[i] == 1) continue;
        elif(a[i] < 0) x *= -1, flag = true;

        a[i] = 0;
        ll cnt = 0; 
        for(ll k = 2; k <= x; k++){
            if(x % k == 0)
                while(x % k == 0) x /= k, cnt++;

            if(cnt % 2 == 1) (a[i] == 0 ? (++a[i] *= k) : a[i] *= k); 

            if(flag && a[i] > 0) a[i] *= -1, flag = false;
            cnt = 0;
        }
    }

    Compress(n);

    forn(i,1,(n + 1)){
        ll k = 0;

        forn(j,i,(n + 1)){
            if(Mark[ a[j] ]) ans[k]++;
            else ans[++k]++, Mark[a[j]] = 1;
        }

        memset(Mark, 0, sizeof(Mark));
    }    

    forn(i,1,n + 1) cout << ans[i] << ' ';

}