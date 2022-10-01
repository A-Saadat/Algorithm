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
ll a[def];
si st;
mll m;
vci x;

int main (void)
{
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        forn(i,0,n){
            cin >> a[i];
            m [ a[i] ]++;
            st.insert(a[i]);
        }

        fort(itr, st) x.pb(*itr);

        bool isOk = true;
        forn(i,0,x.size()){
            if(i == 0) continue;
            if(x[i] == x[i - 1]) continue;
            elif(x[i] - 1 != x[i - 1]) isOk = false;
        }

        ll hm = n % 2 != 0 ? (n + 1) / 2 - 1 : n / 2;

        ll cnt = 0;
        fort(itr, m){
            if(itr->S == 2) cnt++;
            elif(itr->S > 2) cnt += itr->S / 2;
        }


        if((cnt >= hm and isOk) || (isOk and n <= 2)) cout << "YES" << endl;
        else cout << "NO" << endl;
        st.clear(); m.clear(); x.clear();

    }
}