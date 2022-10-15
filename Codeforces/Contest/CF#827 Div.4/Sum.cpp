#include <bits/stdc++.h> 
using namespace std; 

#define def 10000000 
#define forn(i,k,n) for(int i = k; i < n; i++) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define IOS ios_base::sync_with_stdio(false) 
#define msi map<string, int> 
#define mci map<char, int> 
#define mll map<ll, ll> 
#define si set<int> 
#define pb push_back 
#define F first 
#define S second 
#define mp make_pair 
#define gcd __gcd 
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
const char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

bool Checker[def];
ll a[def];

vs ans;

int main (void)
{IOS;

    ll t; cin >> t;
    while(t--){
        bool isOk = false;
        forn(i,0,1000) Checker[i] = 0; 
        forn(i,0,3) cin >> a[i];
        forn(i,0,3){
            ll sum = 0;
            Checker[i] = 1;
            forn(j,0,3)
                if(!Checker[j]) sum += a[j];
            
            if(sum == a[i]) { isOk = true; break;}

            Checker[i] = 0;
        }

        if(isOk) ans.pb("YES");
        else ans.pb("NO");
    }

    forn(i,0,ans.size()) cout << ans[i] << endl;

}

// 4
// 1 4 3
// 0 0 0
// 20 20 20
// 15 7 8
