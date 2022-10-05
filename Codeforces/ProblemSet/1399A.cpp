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

si st;
vci x;

int main (void)
{
    ios_base::sync_with_stdio(false);

    ll t; cin >> t;
    while(t--){
        st.clear(); x.clear();
        ll n; cin >> n;
        forn(i,0,n){
            ll a; cin >> a;
            st.insert(a);
        }
 
        fort(itr, st) x.pb(*itr);
 
        bool isOk = true;
        forn(i,0,x.size()){
            if(x[i] + 1 != x[i + 1] and i + 1 < x.size()) isOk = false;
        }

        if(isOk) cout << "YES" << endl;
        elif(!isOk) cout << "NO" << endl;
        isOk = true;
    }

}