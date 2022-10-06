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
const char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

vci filter(string pri, vci x){
    vci v;
    ll n = x.size();

    if(pri == "odd"){
        forn(i,0,n)
            if(x[i] % 2 != 0) v.pb(x[i]);
    }
    else{
        forn(i,0,n)
            if(x[i] % 2 == 0) v.pb(x[i]);
    }

    return v;
}

vci a;
si s;

int main (void)
{
    ios_base::sync_with_stdio(false);

    ll t; cin >> t;
    forn(idx, 0, t){
        a.clear();
        ll n; cin >> n;
        forn(i,0,n){
            ll x; cin >> x;
            s.insert(x);
        }

        fort(itr, s) a.pb(*itr);

        ll odd = filter("odd", a).size();
        ll even = filter("even", a).size();

        // forn(i,0, a.size()) cout << a[i] << ' ';

        bool isOK = false;
        if(odd == 2 or even == 2) { cout << "YES" << endl;}
        else{
            forn(i,0,n)
                if(a[i] + 1 == a[i + 1] && a[i] - 1 != a[i - 1]) { cout << "YES" << endl; isOK = true; break; };
            
            if(!isOK) cout << "NO" << endl;
        }
    }
}